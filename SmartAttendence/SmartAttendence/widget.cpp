#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QSqlQuery>
#include "retrivewindow.h"
#include "Database.h"
#include <QDebug>
#include <stdio.h>
#include <QMessageBox>
#include <QSqlError>

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
QString Login;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->LoginImage->setPixmap(QPixmap("/home/rahul/Pictures/login.jpeg"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Login_clicked()
{
    Open_Database();
    if(db.open())
    {
        qDebug()<<"Entering into DB...";
    }
    else
    qDebug()<<db.lastError();

    QString Password;
    QSqlQuery query;
    Login = "Select Password from Login_Info where Id ='";
    Login += ui->User->text() + QString("'");
    qDebug()<<Login;
    printf("\n in the path");
    query.exec(Login);
    Password = ui->Password->text();
    Login = ui->User->text().toStdString().c_str();
    while(query.next())
    {
        qDebug()<<query.value(0).toString();
        if(query.value(0).toString().toStdString().c_str() == Password)
        {
            qDebug()<<Login;
            Open_Retrive_Window();

        }

        else
            qDebug()<<"Password wrong, Try again";
    }

    db.close();
    this->close();
//    qDebug()<<"login for next window"<<Login;

}

void Open_Database()
{
    db.setHostName("localhost");
    db.setDatabaseName("Attendance");
    db.setUserName("root");
    db.setPassword("123@123");
    qDebug()<<"Entering into MYSQL...";
}
