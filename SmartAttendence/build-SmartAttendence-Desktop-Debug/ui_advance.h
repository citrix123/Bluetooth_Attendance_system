/********************************************************************************
** Form generated from reading UI file 'advance.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCE_H
#define UI_ADVANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Advance
{
public:
    QWidget *centralwidget;
    QLabel *Option;
    QComboBox *comboBox;
    QTableView *tableView;
    QLineEdit *Id;
    QLineEdit *name;
    QComboBox *Leave_Slots;
    QLabel *EL;
    QLabel *CL;
    QLabel *LWP;
    QLabel *TL;
    QTextEdit *textEdit;
    QLabel *TimeFrom;
    QLabel *TimeTo;
    QDateEdit *DateTo;
    QDateEdit *Datefrom;
    QComboBox *LeaveType;
    QPushButton *proceed;
    QPushButton *back;
    QPushButton *savetofile;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Advance)
    {
        if (Advance->objectName().isEmpty())
            Advance->setObjectName(QStringLiteral("Advance"));
        Advance->resize(539, 563);
        centralwidget = new QWidget(Advance);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Option = new QLabel(centralwidget);
        Option->setObjectName(QStringLiteral("Option"));
        Option->setGeometry(QRect(20, 10, 228, 21));
        QFont font;
        font.setPointSize(14);
        Option->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 60, 421, 27));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(25, 121, 491, 331));
        Id = new QLineEdit(centralwidget);
        Id->setObjectName(QStringLiteral("Id"));
        Id->setGeometry(QRect(160, 50, 231, 27));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(162, 120, 231, 27));
        Leave_Slots = new QComboBox(centralwidget);
        Leave_Slots->setObjectName(QStringLiteral("Leave_Slots"));
        Leave_Slots->setGeometry(QRect(31, 310, 240, 27));
        EL = new QLabel(centralwidget);
        EL->setObjectName(QStringLiteral("EL"));
        EL->setGeometry(QRect(30, 170, 131, 17));
        CL = new QLabel(centralwidget);
        CL->setObjectName(QStringLiteral("CL"));
        CL->setGeometry(QRect(30, 220, 131, 17));
        LWP = new QLabel(centralwidget);
        LWP->setObjectName(QStringLiteral("LWP"));
        LWP->setGeometry(QRect(260, 170, 201, 17));
        TL = new QLabel(centralwidget);
        TL->setObjectName(QStringLiteral("TL"));
        TL->setGeometry(QRect(260, 220, 151, 17));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 360, 311, 78));
        TimeFrom = new QLabel(centralwidget);
        TimeFrom->setObjectName(QStringLiteral("TimeFrom"));
        TimeFrom->setGeometry(QRect(300, 260, 77, 17));
        TimeTo = new QLabel(centralwidget);
        TimeTo->setObjectName(QStringLiteral("TimeTo"));
        TimeTo->setGeometry(QRect(300, 310, 57, 17));
        DateTo = new QDateEdit(centralwidget);
        DateTo->setObjectName(QStringLiteral("DateTo"));
        DateTo->setGeometry(QRect(410, 260, 110, 27));
        Datefrom = new QDateEdit(centralwidget);
        Datefrom->setObjectName(QStringLiteral("Datefrom"));
        Datefrom->setGeometry(QRect(410, 310, 110, 27));
        LeaveType = new QComboBox(centralwidget);
        LeaveType->setObjectName(QStringLiteral("LeaveType"));
        LeaveType->setGeometry(QRect(30, 260, 181, 27));
        proceed = new QPushButton(centralwidget);
        proceed->setObjectName(QStringLiteral("proceed"));
        proceed->setGeometry(QRect(160, 460, 231, 27));
        back = new QPushButton(centralwidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(480, 460, 41, 41));
        savetofile = new QPushButton(centralwidget);
        savetofile->setObjectName(QStringLiteral("savetofile"));
        savetofile->setGeometry(QRect(160, 490, 230, 27));
        Advance->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Advance);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 539, 25));
        Advance->setMenuBar(menubar);
        statusbar = new QStatusBar(Advance);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Advance->setStatusBar(statusbar);

        retranslateUi(Advance);

        QMetaObject::connectSlotsByName(Advance);
    } // setupUi

    void retranslateUi(QMainWindow *Advance)
    {
        Advance->setWindowTitle(QApplication::translate("Advance", "MainWindow", 0));
        Option->setText(QApplication::translate("Advance", "Please Select Your Option:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Advance", "Select", 0)
         << QApplication::translate("Advance", "New Faculty Insert", 0)
         << QApplication::translate("Advance", "Current Faculty Present", 0)
         << QApplication::translate("Advance", "Current Faculty Absent", 0)
         << QApplication::translate("Advance", "Next Holiday declaration", 0)
         << QApplication::translate("Advance", "Faculty Leave Request", 0)
         << QApplication::translate("Advance", "Print Monthly Attendence", 0)
         << QApplication::translate("Advance", "Salary Calculator", 0)
        );
        Id->setText(QString());
        name->setText(QString());
        Leave_Slots->clear();
        Leave_Slots->insertItems(0, QStringList()
         << QApplication::translate("Advance", "Select Leave Category..", 0)
         << QApplication::translate("Advance", "Credit leaves", 0)
         << QApplication::translate("Advance", "Earned Leaves", 0)
         << QApplication::translate("Advance", "Leave without Payment", 0)
        );
        EL->setText(QApplication::translate("Advance", "Earned Leaves:", 0));
        CL->setText(QApplication::translate("Advance", "Credit Leaves:", 0));
        LWP->setText(QApplication::translate("Advance", "Leave Without Payments:", 0));
        TL->setText(QApplication::translate("Advance", "Total Leaves Left:", 0));
        textEdit->setHtml(QApplication::translate("Advance", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Refrence for leave..</p></body></html>", 0));
        TimeFrom->setText(QApplication::translate("Advance", "Time From:", 0));
        TimeTo->setText(QApplication::translate("Advance", "Time To:", 0));
        LeaveType->clear();
        LeaveType->insertItems(0, QStringList()
         << QApplication::translate("Advance", "Select Leave Type..", 0)
         << QApplication::translate("Advance", "Half Day", 0)
         << QApplication::translate("Advance", "Full Day", 0)
        );
        proceed->setText(QApplication::translate("Advance", "Proceed", 0));
        back->setText(QApplication::translate("Advance", "Back", 0));
        savetofile->setText(QApplication::translate("Advance", "Save to .csv", 0));
    } // retranslateUi

};

namespace Ui {
    class Advance: public Ui_Advance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCE_H
