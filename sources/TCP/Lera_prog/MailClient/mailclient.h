#ifndef MAILCLIENT_H
#define MAILCLIENT_H

#include <QMainWindow>
#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QTime>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpSocket>

class QTcpServer;
class QTextEdit;
class QTcpSocket;

namespace Ui {
class MailClient;
}

class MailClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MailClient(const QString& strHost, int nPort, QWidget *parent = 0);
    ~MailClient();

private:
    Ui::MailClient *ui;
    QTcpSocket* m_pTcpSocket;
    QTextEdit* m_ptxtInfo;
    QLineEdit* m_ptxtInput;
    quint16 m_nNextBlockSize;
    QString username;
    void SendToServer(QString str);

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    //void slotSendToServer();
    void slotConnected();
    QString parssingMessage(QString str);


    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_comboBox_activated(const QString &arg1);
    void on_pushButton_2_clicked();
    void on_comboBox_2_activated(const QString &arg1);
    void on_pushButton_3_clicked();
};

#endif // MAILCLIENT_H
