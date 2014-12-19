/********************************************************************************
** Form generated from reading UI file 'retrive_window.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIVE_WINDOW_H
#define UI_RETRIVE_WINDOW_H

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

class Ui_Retrive_Window
{
public:
    QLabel *Name;
    QLabel *Email;
    QLabel *label;
    QLabel *Post;
    QLabel *College;
    QPushButton *Advance;
    QLabel *Specification;
    QPushButton *Modify;
    QPushButton *checkleaves;
    QLabel *Address;
    QLabel *label_3;
    QLabel *Mobile;
    QLabel *Logo;
    QLineEdit *MAddress;
    QLineEdit *MSpecificatio;
    QLineEdit *MTelephone;
    QLineEdit *MEmail;

    void setupUi(QWidget *Retrive_Window)
    {
        if (Retrive_Window->objectName().isEmpty())
            Retrive_Window->setObjectName(QStringLiteral("Retrive_Window"));
        Retrive_Window->resize(530, 454);
        Name = new QLabel(Retrive_Window);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setGeometry(QRect(150, 90, 151, 21));
        QFont font;
        font.setPointSize(15);
        Name->setFont(font);
        Email = new QLabel(Retrive_Window);
        Email->setObjectName(QStringLiteral("Email"));
        Email->setGeometry(QRect(150, 250, 261, 21));
        Email->setFont(font);
        label = new QLabel(Retrive_Window);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 90, 102, 24));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        Post = new QLabel(Retrive_Window);
        Post->setObjectName(QStringLiteral("Post"));
        Post->setGeometry(QRect(150, 220, 221, 21));
        Post->setFont(font);
        College = new QLabel(Retrive_Window);
        College->setObjectName(QStringLiteral("College"));
        College->setGeometry(QRect(150, 310, 151, 21));
        College->setFont(font);
        Advance = new QPushButton(Retrive_Window);
        Advance->setObjectName(QStringLiteral("Advance"));
        Advance->setGeometry(QRect(200, 390, 140, 50));
        Specification = new QLabel(Retrive_Window);
        Specification->setObjectName(QStringLiteral("Specification"));
        Specification->setGeometry(QRect(150, 190, 151, 21));
        Specification->setFont(font);
        Modify = new QPushButton(Retrive_Window);
        Modify->setObjectName(QStringLiteral("Modify"));
        Modify->setGeometry(QRect(10, 390, 150, 50));
        checkleaves = new QPushButton(Retrive_Window);
        checkleaves->setObjectName(QStringLiteral("checkleaves"));
        checkleaves->setGeometry(QRect(370, 390, 150, 50));
        Address = new QLabel(Retrive_Window);
        Address->setObjectName(QStringLiteral("Address"));
        Address->setGeometry(QRect(150, 120, 151, 21));
        Address->setFont(font);
        label_3 = new QLabel(Retrive_Window);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 20, 161, 27));
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_3->setFont(font2);
        Mobile = new QLabel(Retrive_Window);
        Mobile->setObjectName(QStringLiteral("Mobile"));
        Mobile->setGeometry(QRect(150, 280, 151, 21));
        Mobile->setFont(font);
        Logo = new QLabel(Retrive_Window);
        Logo->setObjectName(QStringLiteral("Logo"));
        Logo->setGeometry(QRect(380, 40, 111, 130));
        MAddress = new QLineEdit(Retrive_Window);
        MAddress->setObjectName(QStringLiteral("MAddress"));
        MAddress->setGeometry(QRect(150, 120, 161, 61));
        MSpecificatio = new QLineEdit(Retrive_Window);
        MSpecificatio->setObjectName(QStringLiteral("MSpecificatio"));
        MSpecificatio->setGeometry(QRect(150, 190, 161, 27));
        MTelephone = new QLineEdit(Retrive_Window);
        MTelephone->setObjectName(QStringLiteral("MTelephone"));
        MTelephone->setGeometry(QRect(150, 280, 161, 27));
        MEmail = new QLineEdit(Retrive_Window);
        MEmail->setObjectName(QStringLiteral("MEmail"));
        MEmail->setGeometry(QRect(150, 250, 261, 27));

        retranslateUi(Retrive_Window);

        QMetaObject::connectSlotsByName(Retrive_Window);
    } // setupUi

    void retranslateUi(QWidget *Retrive_Window)
    {
        Retrive_Window->setWindowTitle(QApplication::translate("Retrive_Window", "Form", 0));
        Name->setText(QApplication::translate("Retrive_Window", "Name", 0));
        Email->setText(QApplication::translate("Retrive_Window", "Email", 0));
        label->setText(QApplication::translate("Retrive_Window", "Welcome !", 0));
        Post->setText(QApplication::translate("Retrive_Window", "Post", 0));
        College->setText(QApplication::translate("Retrive_Window", "SRCEM", 0));
        Advance->setText(QApplication::translate("Retrive_Window", "Advance settings", 0));
        Specification->setText(QApplication::translate("Retrive_Window", "Specification", 0));
        Modify->setText(QApplication::translate("Retrive_Window", "Modify", 0));
        checkleaves->setText(QApplication::translate("Retrive_Window", "Leaves Status", 0));
        Address->setText(QApplication::translate("Retrive_Window", "Address", 0));
        label_3->setText(QApplication::translate("Retrive_Window", "Faculty Profile", 0));
        Mobile->setText(QApplication::translate("Retrive_Window", "Telephone", 0));
        Logo->setText(QApplication::translate("Retrive_Window", "LOGO", 0));
    } // retranslateUi

};

namespace Ui {
    class Retrive_Window: public Ui_Retrive_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIVE_WINDOW_H
