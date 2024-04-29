/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *mainConsole;
    QPushButton *southButton;
    QPushButton *westButton;
    QPushButton *northButton;
    QPushButton *teleportButton;
    QPushButton *eastButton;
    QPushButton *help;
    QPushButton *viewMap;
    QPushButton *viewCharInfo;
    QPushButton *viewRoomItems;
    QPushButton *viewCharItems;
    QListWidget *listWidget;
    QTextEdit *staminaDisplay;
    QPushButton *selectSuspect1;
    QPushButton *selectSuspect2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(618, 341);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        mainConsole = new QTextEdit(centralWidget);
        mainConsole->setObjectName("mainConsole");
        mainConsole->setGeometry(QRect(10, 10, 321, 191));
        mainConsole->setReadOnly(true);
        southButton = new QPushButton(centralWidget);
        southButton->setObjectName("southButton");
        southButton->setGeometry(QRect(50, 250, 51, 41));
        westButton = new QPushButton(centralWidget);
        westButton->setObjectName("westButton");
        westButton->setGeometry(QRect(10, 210, 41, 81));
        northButton = new QPushButton(centralWidget);
        northButton->setObjectName("northButton");
        northButton->setGeometry(QRect(50, 210, 51, 41));
        northButton->setAutoFillBackground(false);
        teleportButton = new QPushButton(centralWidget);
        teleportButton->setObjectName("teleportButton");
        teleportButton->setGeometry(QRect(150, 210, 51, 81));
        eastButton = new QPushButton(centralWidget);
        eastButton->setObjectName("eastButton");
        eastButton->setGeometry(QRect(100, 210, 41, 81));
        help = new QPushButton(centralWidget);
        help->setObjectName("help");
        help->setGeometry(QRect(270, 250, 61, 41));
        viewMap = new QPushButton(centralWidget);
        viewMap->setObjectName("viewMap");
        viewMap->setGeometry(QRect(210, 250, 61, 41));
        viewCharInfo = new QPushButton(centralWidget);
        viewCharInfo->setObjectName("viewCharInfo");
        viewCharInfo->setGeometry(QRect(210, 210, 121, 41));
        viewRoomItems = new QPushButton(centralWidget);
        viewRoomItems->setObjectName("viewRoomItems");
        viewRoomItems->setGeometry(QRect(340, 210, 261, 41));
        viewCharItems = new QPushButton(centralWidget);
        viewCharItems->setObjectName("viewCharItems");
        viewCharItems->setGeometry(QRect(340, 250, 261, 41));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(340, 80, 261, 121));
        staminaDisplay = new QTextEdit(centralWidget);
        staminaDisplay->setObjectName("staminaDisplay");
        staminaDisplay->setGeometry(QRect(340, 10, 261, 61));
        staminaDisplay->setReadOnly(true);
        selectSuspect1 = new QPushButton(centralWidget);
        selectSuspect1->setObjectName("selectSuspect1");
        selectSuspect1->setGeometry(QRect(10, 300, 291, 31));
        selectSuspect2 = new QPushButton(centralWidget);
        selectSuspect2->setObjectName("selectSuspect2");
        selectSuspect2->setGeometry(QRect(319, 300, 281, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        southButton->setText(QCoreApplication::translate("MainWindow", "South", nullptr));
        westButton->setText(QCoreApplication::translate("MainWindow", "West", nullptr));
        northButton->setText(QCoreApplication::translate("MainWindow", "North", nullptr));
        teleportButton->setText(QCoreApplication::translate("MainWindow", "Teleport", nullptr));
        eastButton->setText(QCoreApplication::translate("MainWindow", "East", nullptr));
        help->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        viewMap->setText(QCoreApplication::translate("MainWindow", "View Map", nullptr));
        viewCharInfo->setText(QCoreApplication::translate("MainWindow", "View Character Info", nullptr));
        viewRoomItems->setText(QCoreApplication::translate("MainWindow", "View Room Items", nullptr));
        viewCharItems->setText(QCoreApplication::translate("MainWindow", "View Character Items", nullptr));
        selectSuspect1->setText(QCoreApplication::translate("MainWindow", "It's Suspect 1!", nullptr));
        selectSuspect2->setText(QCoreApplication::translate("MainWindow", "It's Suspect 2!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
