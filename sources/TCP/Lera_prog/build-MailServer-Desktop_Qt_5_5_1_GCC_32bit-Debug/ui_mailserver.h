/********************************************************************************
** Form generated from reading UI file 'mailserver.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILSERVER_H
#define UI_MAILSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MailServer
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MailServer)
    {
        if (MailServer->objectName().isEmpty())
            MailServer->setObjectName(QStringLiteral("MailServer"));
        MailServer->resize(441, 374);
        centralWidget = new QWidget(MailServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 421, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        MailServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MailServer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 441, 27));
        MailServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MailServer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MailServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MailServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MailServer->setStatusBar(statusBar);

        retranslateUi(MailServer);

        QMetaObject::connectSlotsByName(MailServer);
    } // setupUi

    void retranslateUi(QMainWindow *MailServer)
    {
        MailServer->setWindowTitle(QApplication::translate("MailServer", "MailServer", 0));
        label->setText(QApplication::translate("MailServer", "Server", 0));
    } // retranslateUi

};

namespace Ui {
    class MailServer: public Ui_MailServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILSERVER_H
