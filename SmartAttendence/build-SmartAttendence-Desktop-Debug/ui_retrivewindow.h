/********************************************************************************
** Form generated from reading UI file 'retrivewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIVEWINDOW_H
#define UI_RETRIVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RetriveWindow
{
public:
    QLabel *label;
    QLabel *Name;
    QLabel *Address;
    QLabel *Specification;
    QLabel *Post;
    QLabel *Email;
    QLabel *Mobile;
    QPushButton *Modify;
    QPushButton *checkleaves;
    QLabel *College;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *RetriveWindow)
    {
        if (RetriveWindow->objectName().isEmpty())
            RetriveWindow->setObjectName(QStringLiteral("RetriveWindow"));
        RetriveWindow->resize(550, 456);
        label = new QLabel(RetriveWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 90, 102, 24));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        Name = new QLabel(RetriveWindow);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setGeometry(QRect(160, 90, 151, 21));
        QFont font1;
        font1.setPointSize(15);
        Name->setFont(font1);
        Address = new QLabel(RetriveWindow);
        Address->setObjectName(QStringLiteral("Address"));
        Address->setGeometry(QRect(160, 120, 151, 21));
        Address->setFont(font1);
        Specification = new QLabel(RetriveWindow);
        Specification->setObjectName(QStringLiteral("Specification"));
        Specification->setGeometry(QRect(160, 150, 151, 21));
        Specification->setFont(font1);
        Post = new QLabel(RetriveWindow);
        Post->setObjectName(QStringLiteral("Post"));
        Post->setGeometry(QRect(160, 180, 151, 21));
        Post->setFont(font1);
        Email = new QLabel(RetriveWindow);
        Email->setObjectName(QStringLiteral("Email"));
        Email->setGeometry(QRect(160, 210, 151, 21));
        Email->setFont(font1);
        Mobile = new QLabel(RetriveWindow);
        Mobile->setObjectName(QStringLiteral("Mobile"));
        Mobile->setGeometry(QRect(160, 240, 151, 21));
        Mobile->setFont(font1);
        Modify = new QPushButton(RetriveWindow);
        Modify->setObjectName(QStringLiteral("Modify"));
        Modify->setGeometry(QRect(20, 390, 150, 50));
        checkleaves = new QPushButton(RetriveWindow);
        checkleaves->setObjectName(QStringLiteral("checkleaves"));
        checkleaves->setGeometry(QRect(380, 390, 150, 50));
        College = new QLabel(RetriveWindow);
        College->setObjectName(QStringLiteral("College"));
        College->setGeometry(QRect(160, 270, 151, 21));
        College->setFont(font1);
        label_2 = new QLabel(RetriveWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 30, 111, 101));
        label_3 = new QLabel(RetriveWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 20, 161, 27));
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_3->setFont(font2);
        pushButton = new QPushButton(RetriveWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 390, 140, 50));

        retranslateUi(RetriveWindow);

        QMetaObject::connectSlotsByName(RetriveWindow);
    } // setupUi

    void retranslateUi(QWidget *RetriveWindow)
    {
        RetriveWindow->setWindowTitle(QApplication::translate("RetriveWindow", "Form", 0));
        label->setText(QApplication::translate("RetriveWindow", "Welcome !", 0));
        Name->setText(QApplication::translate("RetriveWindow", "Name", 0));
        Address->setText(QApplication::translate("RetriveWindow", "Address", 0));
        Specification->setText(QApplication::translate("RetriveWindow", "Specification", 0));
        Post->setText(QApplication::translate("RetriveWindow", "Post", 0));
        Email->setText(QApplication::translate("RetriveWindow", "Email", 0));
        Mobile->setText(QApplication::translate("RetriveWindow", "Telephone", 0));
        Modify->setText(QApplication::translate("RetriveWindow", "Modify", 0));
        checkleaves->setText(QApplication::translate("RetriveWindow", "Check Leaves", 0));
        College->setText(QApplication::translate("RetriveWindow", "SRCEM", 0));
        label_2->setText(QApplication::translate("RetriveWindow", "LOGO", 0));
        label_3->setText(QApplication::translate("RetriveWindow", "Faculty Profile", 0));
        pushButton->setText(QApplication::translate("RetriveWindow", "Advance settings", 0));
    } // retranslateUi

};

namespace Ui {
    class RetriveWindow: public Ui_RetriveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIVEWINDOW_H
