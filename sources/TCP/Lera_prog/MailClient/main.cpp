#include "mailclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MailClient client("localhost", 2323);
    client.show();

    return a.exec();
}
