#include "retrive_window.h"
#include "ui_retrive_window.h"
#include <QDebug>
#include "Database.h"
#include "widget.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "checkleaves.h"
#include "advance.h"

bool i = true;
Retrive_Window *r;
Retrive_Window::Retrive_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Retrive_Window)
{
    ui->setupUi(this);

    ui->Advance->setVisible(false);
    ui->MAddress->setVisible(false);
    ui->MEmail->setVisible(false);
    ui->MTelephone->setVisible(false);
    ui->MSpecificatio->setVisible(false);
    qDebug()<<"welcome to retrive window..";
    qDebug()<<Login;
    ui->Logo->setPixmap(QPixmap("/home/rahul/Pictures/Logo.jpeg"));
    QString Query = "select Name, Address, Degree, Designation, E_mail, Phone_No from Faculty_Info where Id = '";
    Query += Login + "'";
    qDebug()<<Query;
    QSqlQuery q;
    Open_Database();
    db.open();
    q.exec(Query);

    while (q.next()) {

        if(q.value(3).toString().toStdString() == "Admin")
        {
            qDebug()<<"welcome Admin";
            ui->Advance->setVisible(true);
        }
        qDebug()<<q.value(0).toString();
        ui->Name->setText(q.value(0).toString());
        qDebug()<<q.value(1).toString();
        ui->Address->setText(q.value(1).toString());
        qDebug()<<q.value(2).toString();
        ui->Specification->setText(q.value(2).toString());
        qDebug()<<q.value(3).toString();

        ui->Post->setText(q.value(3).toString());
        qDebug()<<q.value(4).toString();
        ui->Email->setText(q.value(4).toString());
        qDebug()<<q.value(5).toString();
        ui->Mobile->setText(q.value(5).toString());



    }

}

Retrive_Window::~Retrive_Window()
{
    delete ui;
}

void Open_Retrive_Window()
{
    r = new Retrive_Window();
    r->show();
}

void Retrive_Window::on_Modify_clicked()
{

    if(i)
    {
        ui->MAddress->setVisible(true);
        ui->MAddress->setText(ui->Address->text());
        ui->MEmail->setVisible(true);
        ui->MEmail->setText(ui->Email->text());
        ui->MTelephone->setVisible(true);
        ui->MTelephone->setText(ui->Mobile->text());
        ui->MSpecificatio->setVisible(true);
        ui->MSpecificatio->setText(ui->Specification->text());
        qDebug()<<i;
        i = false;
    }
    else if(!i)
    {
        Open_Database();
        db.open();
        QSqlQuery query;
        QString q;
        q = "UPDATE Faculty_Info set Address = '";
        q += ui->MAddress->text() + QString("',");
        q += QString("E_mail = '") + ui->MEmail->text() + QString("',");
        q += QString("Phone_No = '") + ui->MTelephone->text() + QString("',");
        q += QString("Degree = '") + ui->MSpecificatio->text() + QString("'");
        q += QString("where Id ='") + Login + QString("'");

        qDebug()<<q;
        query.exec(q);
        qDebug()<<"in false loop";
        q = "SELECT E_mail, Phone_No, Degree, Address From Faculty_Info WHERE Id = '";
        q += Login + QString("'");
        qDebug()<<q;
        query.exec(q);
        while(query.next())
        {
            qDebug()<<query.value(0).toString();
            ui->Email->setText(query.value(0).toString());
            qDebug()<<query.value(1).toString();
            ui->Mobile->setText(query.value(1).toString());
            qDebug()<<query.value(2).toString();
            ui->Specification->setText(query.value(2).toString());
            qDebug()<<query.value(3).toString();

            ui->Address->setText(query.value(3).toString());
        }
        ui->MAddress->setVisible(false);
        ui->MEmail->setVisible(false);
        ui->MTelephone->setVisible(false);
        ui->MSpecificatio->setVisible(false);
        i = true;

    }
}

void Retrive_Window::on_checkleaves_clicked()
{
    Open_Leave_Window();
}

void Retrive_Window::on_Advance_clicked()
{
    Open_Advance_Window();
}
