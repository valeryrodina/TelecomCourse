#ifndef MAILSERVER_H
#define MAILSERVER_H

#include <QApplication>
#include <QMainWindow>
//#include <QWidget>
#include <QMessageBox>
#include <QTextEdit>
#include <QLabel>
#include <QTime>
#include <QFile>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>


class QTcpServer;
class QTextEdit;
class QTcpSocket;


namespace Ui {
class MailServer;
}

class MailServer : public QMainWindow
{
    Q_OBJECT

    private:
        QTcpServer* m_ptcpServer;
        QTextEdit* m_ptxt;
        quint16 m_nNextBlockSize;
        Ui::MailServer *ui;
        bool checUsername(QString name);
        QString parssingMessage(QTcpSocket* pSocket, QString str);
        QFile logins;

    private:
        void sendToClient(QTcpSocket* pSocket, const QString& str);

    public slots:
        virtual void slotNewConnection();
        void slotReadClient();

    public:
        explicit MailServer(QString host, int nPort, QWidget *parent = 0);
        ~MailServer();

};

#endif // MAILSERVER_H
