/********************************************************************************
** Form generated from reading UI file 'ModbusTcpClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUSTCPCLIENT_H
#define UI_MODBUSTCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModbusTcpClient
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *cbRegisterType;
    QPushButton *connectButton;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLineEdit *writeadressEdit;
    QPushButton *sendButton;
    QPushButton *sendButton_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *ReadAdresslineEdit;
    QPushButton *readButton;
    QPushButton *sendButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModbusTcpClient)
    {
        if (ModbusTcpClient->objectName().isEmpty())
            ModbusTcpClient->setObjectName(QStringLiteral("ModbusTcpClient"));
        ModbusTcpClient->resize(506, 437);
        centralWidget = new QWidget(ModbusTcpClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        cbRegisterType = new QComboBox(centralWidget);
        cbRegisterType->setObjectName(QStringLiteral("cbRegisterType"));

        horizontalLayout->addWidget(cbRegisterType);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout->addWidget(connectButton);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_4->addWidget(textEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        writeadressEdit = new QLineEdit(centralWidget);
        writeadressEdit->setObjectName(QStringLiteral("writeadressEdit"));

        horizontalLayout_3->addWidget(writeadressEdit);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout_3->addWidget(sendButton);

        sendButton_3 = new QPushButton(centralWidget);
        sendButton_3->setObjectName(QStringLiteral("sendButton_3"));

        horizontalLayout_3->addWidget(sendButton_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_5->addLayout(verticalLayout_2);

        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout_5->addWidget(textEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        ReadAdresslineEdit = new QLineEdit(centralWidget);
        ReadAdresslineEdit->setObjectName(QStringLiteral("ReadAdresslineEdit"));

        horizontalLayout_2->addWidget(ReadAdresslineEdit);

        readButton = new QPushButton(centralWidget);
        readButton->setObjectName(QStringLiteral("readButton"));

        horizontalLayout_2->addWidget(readButton);

        sendButton_4 = new QPushButton(centralWidget);
        sendButton_4->setObjectName(QStringLiteral("sendButton_4"));

        horizontalLayout_2->addWidget(sendButton_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        ModbusTcpClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ModbusTcpClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 506, 26));
        ModbusTcpClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModbusTcpClient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ModbusTcpClient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ModbusTcpClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ModbusTcpClient->setStatusBar(statusBar);

        retranslateUi(ModbusTcpClient);

        QMetaObject::connectSlotsByName(ModbusTcpClient);
    } // setupUi

    void retranslateUi(QMainWindow *ModbusTcpClient)
    {
        ModbusTcpClient->setWindowTitle(QApplication::translate("ModbusTcpClient", "ModbusTcpClient", Q_NULLPTR));
        label->setText(QApplication::translate("ModbusTcpClient", "IP\347\253\257\345\217\243\345\217\267:", Q_NULLPTR));
        cbRegisterType->clear();
        cbRegisterType->insertItems(0, QStringList()
         << QApplication::translate("ModbusTcpClient", "\347\272\277\345\234\210", Q_NULLPTR)
         << QApplication::translate("ModbusTcpClient", "\347\246\273\346\225\243\350\276\223\345\205\245", Q_NULLPTR)
         << QApplication::translate("ModbusTcpClient", "\350\276\223\345\205\245\345\257\204\345\255\230\345\231\250", Q_NULLPTR)
         << QApplication::translate("ModbusTcpClient", "\344\277\235\346\214\201\345\257\204\345\255\230\345\231\250", Q_NULLPTR)
        );
        connectButton->setText(QApplication::translate("ModbusTcpClient", "connect", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModbusTcpClient", "\345\206\231\345\205\245\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ModbusTcpClient", "\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        sendButton->setText(QApplication::translate("ModbusTcpClient", "Send", Q_NULLPTR));
        sendButton_3->setText(QApplication::translate("ModbusTcpClient", "\346\270\205\347\251\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("ModbusTcpClient", "\350\257\273\345\217\226\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ModbusTcpClient", "\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        readButton->setText(QApplication::translate("ModbusTcpClient", "Read", Q_NULLPTR));
        sendButton_4->setText(QApplication::translate("ModbusTcpClient", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModbusTcpClient: public Ui_ModbusTcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSTCPCLIENT_H
