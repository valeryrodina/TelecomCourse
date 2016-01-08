#include "mailserver.h"
#include "ui_mailserver.h"

MailServer::MailServer(QString host, int nPort ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MailServer),
    m_nNextBlockSize(0)
{
    m_ptcpServer = new QTcpServer(this);
    if (!m_ptcpServer->listen(QHostAddress::Any, nPort)) {
        QMessageBox::critical(0,
                                "Server Error",
                                "Unable to start the server:"
                                + m_ptcpServer->errorString()
                              );
        m_ptcpServer->close();
        return;
    }

    connect(m_ptcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    ui->setupUi(this);
}

void MailServer::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();

    connect(pClientSocket, SIGNAL(disconnected()), pClientSocket, SLOT(deleteLater()));
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    sendToClient(pClientSocket, "u%DConnected!");
}

void MailServer::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_5);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
        }
        in >> m_nNextBlockSize;
    }

    if (pClientSocket->bytesAvailable() < m_nNextBlockSize)
        break;

    QTime time;
    QString str;
    in >> time >> str;

    QString strMessage = time.toString() + " " + "Client has sent — " + str;


    strMessage = parssingMessage(pClientSocket, str);
    ui->textEdit->append(strMessage);
    m_nNextBlockSize = 0;
    //sendToClient(pClientSocket, "Server Response: Received \"" + str + "\"");
    }
}

bool MailServer::checUsername(QString name){

    logins.setFileName("../login_pass.lp");
    if (logins.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&logins);
        QString line;
        while (!in.atEnd()){
        line = in.readLine();
            if (line == name){
                logins.close();
                return true;
            }
        }
    }
    logins.close();
    return false;
}

QString MailServer::parssingMessage(QTcpSocket* pSocket, QString str){

    QStringList blocks;
    blocks = str.split("%D");
    qDebug() << blocks.at(0);
    if (blocks.at(0) == "u"){
        if (!checUsername(blocks.at(1))){
            sendToClient(pSocket, "u%DUsername incorrect!");
            return "User: " + blocks.at(1) + " Connection error. Bad username";
        }
        else
            sendToClient(pSocket, "u%DRegister User Ok!");
            return "User: " + blocks.at(1) + " Connected!";
    }

    else if (blocks.at(0) == "s"){
        if (!checUsername(blocks.at(2))){
            sendToClient(pSocket,"s%D" + blocks.at(2) + " Bad username recipient");
            return blocks.at(2) + " Bad username recipient";
        }
        else{
            QDateTime CurrentTime;
            CurrentTime = QDateTime::currentDateTime();
            QFile mail("clients/" + blocks.at(1) + "/sent/" + blocks.at(2) + CurrentTime.toString("<ddMMyyyy>[hh:mm:ss]"));
            if (mail.open(QFile::ReadWrite | QFile::Text))
            {
                QTextStream in(&mail);
                in << "Topic: " << blocks.at(3) << "\n\n";
                in << blocks.at(4);
            }

            mail.close();

            QFile mail1("clients/" + blocks.at(2) + "/inbox/" + blocks.at(1) + CurrentTime.toString("<ddMMyyyy>[hh:mm:ss]"));
            if (mail1.open(QFile::ReadWrite | QFile::Text))
            {
                QTextStream in(&mail1);
                in << "Topic: " << blocks.at(3) << "\n\n";
                in << blocks.at(4);
            }

            mail1.close();
            sendToClient(pSocket,"s%D" + blocks.at(2) + ": has received a letter!");

            return "the user: " + blocks.at(1) + " sent mail " + blocks.at(2);
        }

    }

    else if (blocks.at(0) == "r"){
        QFile mail("clients/" + blocks.at(1) + "/" + blocks.at(2) + "/" + blocks.at(3));
        if (mail.open(QFile::ReadOnly | QFile::Text))
        {
            QString text;
            QTextStream in(&mail);
            QString line;

            line = in.readLine();
            text = line + "%D";

            while (!in.atEnd()){
                line = in.readLine();
                    text += line + '\n';
            }

            sendToClient(pSocket,"r%D" + blocks.at(2) + "%D" + blocks.at(3) + "%D" + text);
            return "The user: " + blocks.at(1) + " views: " + blocks.at(3);
        }
        else
            sendToClient(pSocket,"r%D" + blocks.at(2) + "%D"  + blocks.at(3) + "%D" + " Error mail name");

        return "The user: " +  blocks.at(1) + " Error mail name";
    }

    else if (blocks.at(0) == "i"){
        QDir dirInbox("clients/" + blocks.at(1) + "/inbox");
        QStringList inbox = dirInbox.entryList(QStringList("*"));
        sendToClient(pSocket,"i%DInbox%D" +  inbox.join("%D"));

        QDir dirSent("clients/" + blocks.at(1) + "/sent");
        QStringList sent = dirSent.entryList(QStringList("*"));
        sendToClient(pSocket,"i%DSent%D" +  sent.join("%D"));
        //ui->textEdit->append((QString)sent.join("\n"));

        return "the user: " + blocks.at(1) + " received information";
    }

     return str.replace("%D",",");
}

void MailServer::sendToClient(QTcpSocket* pSocket, const QString& str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    pSocket->write(arrBlock);
    qDebug() << arrBlock.toHex();
}

MailServer::~MailServer()
{
    delete ui;
}
