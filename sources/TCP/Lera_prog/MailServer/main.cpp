#include "mailserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MailServer server("localhost", 2323);
    server.show();

    return a.exec();
}
