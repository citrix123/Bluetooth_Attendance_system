/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *User;
    QLineEdit *Password;
    QLabel *label_2;
    QPushButton *Login;
    QLabel *LoginImage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(386, 397);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 263, 28));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(18);
        label->setFont(font);
        User = new QLineEdit(Widget);
        User->setObjectName(QStringLiteral("User"));
        User->setGeometry(QRect(100, 210, 191, 27));
        Password = new QLineEdit(Widget);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(100, 280, 191, 27));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 250, 67, 17));
        Login = new QPushButton(Widget);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(140, 330, 99, 41));
        LoginImage = new QLabel(Widget);
        LoginImage->setObjectName(QStringLiteral("LoginImage"));
        LoginImage->setGeometry(QRect(140, 70, 119, 126));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "Smart Attendence login panel", 0));
        label_2->setText(QApplication::translate("Widget", "Password", 0));
        Login->setText(QApplication::translate("Widget", "Log In", 0));
        LoginImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
