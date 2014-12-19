/********************************************************************************
** Form generated from reading UI file 'checkleaves.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKLEAVES_H
#define UI_CHECKLEAVES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckLeaves
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *TL;
    QLabel *CL;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *EL;
    QLabel *LWP;
    QMenuBar *menubar;
    QMenu *menuLeaves;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CheckLeaves)
    {
        if (CheckLeaves->objectName().isEmpty())
            CheckLeaves->setObjectName(QStringLiteral("CheckLeaves"));
        CheckLeaves->resize(800, 487);
        centralwidget = new QWidget(CheckLeaves);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 140, 771, 300));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 111, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 112, 22));
        label_2->setFont(font);
        TL = new QLabel(centralwidget);
        TL->setObjectName(QStringLiteral("TL"));
        TL->setGeometry(QRect(160, 20, 67, 20));
        CL = new QLabel(centralwidget);
        CL->setObjectName(QStringLiteral("CL"));
        CL->setGeometry(QRect(160, 80, 67, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 20, 120, 22));
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 80, 220, 22));
        label_6->setFont(font);
        EL = new QLabel(centralwidget);
        EL->setObjectName(QStringLiteral("EL"));
        EL->setGeometry(QRect(650, 20, 67, 17));
        LWP = new QLabel(centralwidget);
        LWP->setObjectName(QStringLiteral("LWP"));
        LWP->setGeometry(QRect(650, 80, 67, 17));
        CheckLeaves->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CheckLeaves);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuLeaves = new QMenu(menubar);
        menuLeaves->setObjectName(QStringLiteral("menuLeaves"));
        CheckLeaves->setMenuBar(menubar);
        statusbar = new QStatusBar(CheckLeaves);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CheckLeaves->setStatusBar(statusbar);

        menubar->addAction(menuLeaves->menuAction());

        retranslateUi(CheckLeaves);

        QMetaObject::connectSlotsByName(CheckLeaves);
    } // setupUi

    void retranslateUi(QMainWindow *CheckLeaves)
    {
        CheckLeaves->setWindowTitle(QApplication::translate("CheckLeaves", "MainWindow", 0));
        label->setText(QApplication::translate("CheckLeaves", "Total leaves", 0));
        label_2->setText(QApplication::translate("CheckLeaves", "Credit leaves", 0));
        TL->setText(QApplication::translate("CheckLeaves", "0", 0));
        CL->setText(QApplication::translate("CheckLeaves", "0", 0));
        label_5->setText(QApplication::translate("CheckLeaves", "Earned leaves", 0));
        label_6->setText(QApplication::translate("CheckLeaves", "Leaves without payments", 0));
        EL->setText(QApplication::translate("CheckLeaves", "0", 0));
        LWP->setText(QApplication::translate("CheckLeaves", "0", 0));
        menuLeaves->setTitle(QApplication::translate("CheckLeaves", "Leaves", 0));
    } // retranslateUi

};

namespace Ui {
    class CheckLeaves: public Ui_CheckLeaves {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKLEAVES_H
