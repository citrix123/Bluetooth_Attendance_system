/********************************************************************************
** Form generated from reading UI file 'salary.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALARY_H
#define UI_SALARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Salary
{
public:
    QLabel *label;
    QLabel *HalfDays;
    QLineEdit *Id;
    QLabel *FullDays;
    QPushButton *GetSalary;
    QLabel *Salary_2;

    void setupUi(QWidget *Salary)
    {
        if (Salary->objectName().isEmpty())
            Salary->setObjectName(QStringLiteral("Salary"));
        Salary->resize(400, 374);
        label = new QLabel(Salary);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 142, 24));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        HalfDays = new QLabel(Salary);
        HalfDays->setObjectName(QStringLiteral("HalfDays"));
        HalfDays->setGeometry(QRect(20, 100, 121, 17));
        Id = new QLineEdit(Salary);
        Id->setObjectName(QStringLiteral("Id"));
        Id->setGeometry(QRect(100, 50, 190, 27));
        FullDays = new QLabel(Salary);
        FullDays->setObjectName(QStringLiteral("FullDays"));
        FullDays->setGeometry(QRect(290, 100, 69, 17));
        GetSalary = new QPushButton(Salary);
        GetSalary->setObjectName(QStringLiteral("GetSalary"));
        GetSalary->setGeometry(QRect(130, 300, 120, 27));
        Salary_2 = new QLabel(Salary);
        Salary_2->setObjectName(QStringLiteral("Salary_2"));
        Salary_2->setGeometry(QRect(160, 230, 67, 17));

        retranslateUi(Salary);

        QMetaObject::connectSlotsByName(Salary);
    } // setupUi

    void retranslateUi(QWidget *Salary)
    {
        Salary->setWindowTitle(QApplication::translate("Salary", "Form", 0));
        label->setText(QApplication::translate("Salary", "Salary Widget", 0));
        HalfDays->setText(QApplication::translate("Salary", "Half Days:", 0));
        FullDays->setText(QApplication::translate("Salary", "Full Days:", 0));
        GetSalary->setText(QApplication::translate("Salary", "Salary", 0));
        Salary_2->setText(QApplication::translate("Salary", "Salary", 0));
    } // retranslateUi

};

namespace Ui {
    class Salary: public Ui_Salary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALARY_H
