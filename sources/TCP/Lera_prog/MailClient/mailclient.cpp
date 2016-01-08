#include "mailclient.h"
#include "ui_mailclient.h"

MailClient::MailClient(const QString &strHost, int nPort, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MailClient),
    m_nNextBlockSize(0)
{
    m_pTcpSocket = new QTcpSocket(this);
    ui->setupUi(this);

    m_pTcpSocket->connectToHost(strHost, nPort);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));

    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));

    ui->textEdit->setReadOnly(true);
    ui->textEdit_inbox->setReadOnly(true);
    ui->textEdit_sent->setReadOnly(true);

    //connect(ui->pushButton, SIGNAL(clicked()), SLOT(slotSendToServer()));
    //connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));

}

void MailClient::slotReadyRead()
{
    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_4_5);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (m_pTcpSocket->bytesAvailable() < sizeof(quint16)) {
            break;
            }
            in >> m_nNextBlockSize;
            }
        if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize)
            break;

        QTime time;
        QString str;

        in >> time >> str;

        //qDebug() << str;
        str = parssingMessage(str);
        ui->textEdit->append(time.toString() + " " + str);

        m_nNextBlockSize = 0;
    }
}

void MailClient::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
            "Error: " + (err == QAbstractSocket::HostNotFoundError ?
            "The host was not found." :
            err == QAbstractSocket::RemoteHostClosedError ?
            "The remote host is closed." :
            err == QAbstractSocket::ConnectionRefusedError ?
            "The connection was refused." :
            QString(m_pTcpSocket->errorString())
            );
    ui->textEdit->append(strError);
}

void MailClient::SendToServer(QString str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    m_pTcpSocket->write(arrBlock);
}

void MailClient::slotConnected()
{
    ui->textEdit->append("Received the connected() signal");
}

QString MailClient::parssingMessage(QString str)
{
    QStringList blocks;
    blocks = str.split("%D");
    if (blocks.at(0) == "u"){
        if (blocks.at(1) != "Register User Ok!"){
            bool bOk;
            while(1){
                username = QInputDialog::getText(0, "Connection to server", "Username:", QLineEdit::Normal, "user", &bOk);
                if (bOk)
                    break;
            }
            SendToServer("u%D" + username);

        }
        else
            return username + "connected!";

    }

    else if (blocks.at(0) == "i"){


        if (blocks.at(1) == "Inbox"){
            ui->comboBox_2->clear();
            ui->textEdit_inbox->setText("");
            for (int i = 4; i < blocks.size(); ++i){
                ui->textEdit_inbox->append(blocks.at(i));
                ui->comboBox_2->addItem(blocks.at(i));
            }
            return "Mail \"Sent\" updated!";
        }
        else if (blocks.at(1) == "Sent"){
            ui->comboBox->clear();
            ui->textEdit_sent->setText("");
            for (int i = 4; i < blocks.size(); ++i){
                ui->textEdit_sent->append(blocks.at(i));
                ui->comboBox->addItem(blocks.at(i));
            }
            return "Mail \"Inbox\" updated!";
        }


    }

    else if (blocks.at(0) == "s"){
        QMessageBox* pmbx =
                    new QMessageBox(QMessageBox::Information, "MessageFromServer",
                                    blocks.at(1),
                                    QMessageBox::Ok);
        int n = pmbx->exec();
        delete pmbx;

        if (n == QMessageBox::Ok) {
            ui->lineEdit_topic->clear();
            ui->textEdit_text->clear();
        }
        return blocks.at(1);
    }

    else if (blocks.at(0) == "r"){
        if (blocks.at(1) == "sent"){
            ui->textEdit_sent->clear();
            for (int i = 2; i < blocks.size(); ++i)
                ui->textEdit_sent->append(blocks.at(i));
            return "get Message";
        }
        if (blocks.at(1) == "inbox"){
            ui->textEdit_inbox->clear();
            for (int i = 2; i < blocks.size(); ++i)
                ui->textEdit_inbox->append(blocks.at(i));

            return "get Message";
        }
    }
    return str.remove(0,3).replace("%D", ",");
}

MailClient::~MailClient()
{
    delete ui;
}

void MailClient::on_pushButton_clicked()
{
    SendToServer("i%D" + username);
}

void MailClient::on_pushButton_4_clicked()
{
    SendToServer("s%D" + username + "%D"+ ui->lineEdit_user->text() + "%D" + ui->lineEdit_topic->text() + "%D" + ui->textEdit_text->toPlainText());
}

void MailClient::on_comboBox_activated(const QString &arg1)
{
    SendToServer("r%D" + username + "%D"+ "sent" + "%D" + arg1);
}

void MailClient::on_pushButton_2_clicked()
{
    SendToServer("i%D" + username);
}

void MailClient::on_comboBox_2_activated(const QString &arg1)
{
    SendToServer("r%D" + username + "%D"+ "inbox" + "%D" + arg1);
}

void MailClient::on_pushButton_3_clicked()
{
    SendToServer("i%D" + username);
}
