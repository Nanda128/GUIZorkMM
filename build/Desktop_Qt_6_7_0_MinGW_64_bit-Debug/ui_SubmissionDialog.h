/********************************************************************************
** Form generated from reading UI file 'SubmissionDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBMISSIONDIALOG_H
#define UI_SUBMISSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *backToBedroom;
    QTextBrowser *textBrowser;
    QPushButton *selectSuspect1;
    QPushButton *selectSuspect2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(417, 314);
        backToBedroom = new QPushButton(Form);
        backToBedroom->setObjectName("backToBedroom");
        backToBedroom->setGeometry(QRect(10, 10, 391, 61));
        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 80, 391, 81));
        selectSuspect1 = new QPushButton(Form);
        selectSuspect1->setObjectName("selectSuspect1");
        selectSuspect1->setGeometry(QRect(10, 160, 181, 141));
        selectSuspect2 = new QPushButton(Form);
        selectSuspect2->setObjectName("selectSuspect2");
        selectSuspect2->setGeometry(QRect(239, 160, 161, 141));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        backToBedroom->setText(QCoreApplication::translate("Form", "Back To Bedroom", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">So, who do you think did it? Hit 1 if its Suspect 1, or 2 if its Suspect 2.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"><br /></p></body></html>", nullptr));
        selectSuspect1->setText(QCoreApplication::translate("Form", "It's Suspect 1!", nullptr));
        selectSuspect2->setText(QCoreApplication::translate("Form", "It's Suspect 2!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBMISSIONDIALOG_H
