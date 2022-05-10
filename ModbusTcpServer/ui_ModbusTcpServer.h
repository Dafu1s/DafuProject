/********************************************************************************
** Form generated from reading UI file 'ModbusTcpServer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODBUSTCPSERVER_H
#define UI_MODBUSTCPSERVER_H

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

class Ui_ModbusTcpServer
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *cbRegisterType;
    QPushButton *connectButton;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QLineEdit *readadresslineEdit;
    QPushButton *readdataButton;
    QPushButton *clearButton;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLineEdit *adresslineEdit;
    QPushButton *writeButton;
    QPushButton *clearButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModbusTcpServer)
    {
        if (ModbusTcpServer->objectName().isEmpty())
            ModbusTcpServer->setObjectName(QStringLiteral("ModbusTcpServer"));
        ModbusTcpServer->resize(486, 419);
        centralWidget = new QWidget(ModbusTcpServer);
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

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_5->addWidget(textEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        readadresslineEdit = new QLineEdit(centralWidget);
        readadresslineEdit->setObjectName(QStringLiteral("readadresslineEdit"));

        horizontalLayout_2->addWidget(readadresslineEdit);

        readdataButton = new QPushButton(centralWidget);
        readdataButton->setObjectName(QStringLiteral("readdataButton"));

        horizontalLayout_2->addWidget(readdataButton);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout_2->addWidget(clearButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout_4->addWidget(textEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        adresslineEdit = new QLineEdit(centralWidget);
        adresslineEdit->setObjectName(QStringLiteral("adresslineEdit"));

        horizontalLayout_3->addWidget(adresslineEdit);

        writeButton = new QPushButton(centralWidget);
        writeButton->setObjectName(QStringLiteral("writeButton"));

        horizontalLayout_3->addWidget(writeButton);

        clearButton_2 = new QPushButton(centralWidget);
        clearButton_2->setObjectName(QStringLiteral("clearButton_2"));

        horizontalLayout_3->addWidget(clearButton_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        ModbusTcpServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ModbusTcpServer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 486, 26));
        ModbusTcpServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModbusTcpServer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ModbusTcpServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ModbusTcpServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ModbusTcpServer->setStatusBar(statusBar);

        retranslateUi(ModbusTcpServer);

        QMetaObject::connectSlotsByName(ModbusTcpServer);
    } // setupUi

    void retranslateUi(QMainWindow *ModbusTcpServer)
    {
        ModbusTcpServer->setWindowTitle(QApplication::translate("ModbusTcpServer", "ModbusTcpServer", Q_NULLPTR));
        label->setText(QApplication::translate("ModbusTcpServer", "IP\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit->setText(QString());
        cbRegisterType->clear();
        cbRegisterType->insertItems(0, QStringList()
         << QApplication::translate("ModbusTcpServer", "\347\272\277\345\234\210", Q_NULLPTR)
         << QApplication::translate("ModbusTcpServer", "\347\246\273\346\225\243\350\276\223\345\205\245", Q_NULLPTR)
         << QApplication::translate("ModbusTcpServer", "\350\276\223\345\205\245\345\257\204\345\255\230\345\231\250", Q_NULLPTR)
         << QApplication::translate("ModbusTcpServer", "\344\277\235\346\214\201\345\257\204\345\255\230\345\231\250", Q_NULLPTR)
        );
        connectButton->setText(QApplication::translate("ModbusTcpServer", "connect", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModbusTcpServer", "\346\216\245\346\224\266\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ModbusTcpServer", "\345\234\260\345\235\200", Q_NULLPTR));
        readdataButton->setText(QApplication::translate("ModbusTcpServer", "\350\257\273\345\217\226\346\225\260\346\215\256", Q_NULLPTR));
        clearButton->setText(QApplication::translate("ModbusTcpServer", "\346\270\205\351\231\244", Q_NULLPTR));
        label_3->setText(QApplication::translate("ModbusTcpServer", "\345\206\231\345\205\245\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ModbusTcpServer", "\345\234\260\345\235\200:", Q_NULLPTR));
        writeButton->setText(QApplication::translate("ModbusTcpServer", "\345\206\231\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        clearButton_2->setText(QApplication::translate("ModbusTcpServer", "\346\270\205\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModbusTcpServer: public Ui_ModbusTcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODBUSTCPSERVER_H
