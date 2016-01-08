/********************************************************************************
** Form generated from reading UI file 'mailclient.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILCLIENT_H
#define UI_MAILCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MailClient
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_inbox;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit_sent;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_topic;
    QTextEdit *textEdit_text;
    QLabel *label_4;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QLineEdit *lineEdit_user;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MailClient)
    {
        if (MailClient->objectName().isEmpty())
            MailClient->setObjectName(QStringLiteral("MailClient"));
        MailClient->resize(516, 660);
        centralWidget = new QWidget(MailClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 511, 591));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 491, 541));
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

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_3->addWidget(comboBox);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout_3, 2, 1, 1, 1);

        textEdit_inbox = new QTextEdit(verticalLayoutWidget);
        textEdit_inbox->setObjectName(QStringLiteral("textEdit_inbox"));

        gridLayout->addWidget(textEdit_inbox, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        textEdit_sent = new QTextEdit(verticalLayoutWidget);
        textEdit_sent->setObjectName(QStringLiteral("textEdit_sent"));

        gridLayout->addWidget(textEdit_sent, 2, 0, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_4->addWidget(comboBox_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_4->addWidget(pushButton_3);


        gridLayout->addLayout(verticalLayout_4, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 331, 301));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_topic = new QLineEdit(gridLayoutWidget_2);
        lineEdit_topic->setObjectName(QStringLiteral("lineEdit_topic"));

        gridLayout_2->addWidget(lineEdit_topic, 0, 1, 1, 1);

        textEdit_text = new QTextEdit(gridLayoutWidget_2);
        textEdit_text->setObjectName(QStringLiteral("textEdit_text"));

        gridLayout_2->addWidget(textEdit_text, 2, 0, 1, 2);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_user = new QLineEdit(gridLayoutWidget_2);
        lineEdit_user->setObjectName(QStringLiteral("lineEdit_user"));

        gridLayout_2->addWidget(lineEdit_user, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        MailClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MailClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 516, 27));
        MailClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MailClient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MailClient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MailClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MailClient->setStatusBar(statusBar);

        retranslateUi(MailClient);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MailClient);
    } // setupUi

    void retranslateUi(QMainWindow *MailClient)
    {
        MailClient->setWindowTitle(QApplication::translate("MailClient", "MailClient", 0));
        label->setText(QApplication::translate("MailClient", "Client", 0));
        pushButton_2->setText(QApplication::translate("MailClient", "Go back", 0));
        label_2->setText(QApplication::translate("MailClient", "sent", 0));
        label_3->setText(QApplication::translate("MailClient", "inbox", 0));
        pushButton_3->setText(QApplication::translate("MailClient", "Go back", 0));
        pushButton->setText(QApplication::translate("MailClient", "Update", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MailClient", "Tab 1", 0));
        label_4->setText(QApplication::translate("MailClient", "Topic", 0));
        pushButton_4->setText(QApplication::translate("MailClient", "Send", 0));
        label_5->setText(QApplication::translate("MailClient", "Recipient", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MailClient", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MailClient: public Ui_MailClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILCLIENT_H
