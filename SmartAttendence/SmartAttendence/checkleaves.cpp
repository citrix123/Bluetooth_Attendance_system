#include "checkleaves.h"
#include "ui_checkleaves.h"
#include <QTableView>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <Database.h>
#include "widget.h"
#include "QDebug"
CheckLeaves *c;
QSqlQueryModel *model;
QSqlQuery query;
CheckLeaves::CheckLeaves(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckLeaves)
{
    ui->setupUi(this);
    Open_Database();
    db.open();
    QString q;
    q = "Select Total_Leaves, Credit_Leaves, Earned_Leaves, LWP From Faculty_Info where Id = '";
    q += Login + QString("'");
    qDebug()<<q;
    query.exec(q);
    while(query.next())
    {
        qDebug()<<query.value(0).toString();
        ui->TL->setText(query.value(0).toString());
        qDebug()<<query.value(1).toString();
        ui->CL->setText(query.value(1).toString());
        qDebug()<<query.value(2).toString();
        ui->EL->setText(query.value(2).toString());
        qDebug()<<query.value(3).toString();
        ui->LWP->setText(query.value(3).toString());
    }
    qDebug()<<"Moving to Tableview..";
    q = "SELECT * FROM Leave_Info Where Id ='";
    q += Login + QString("'");
    qDebug()<<q;
    model = new QSqlQueryModel();
    model->setQuery(q);
    ui->tableView->setModel(model);
}

CheckLeaves::~CheckLeaves()
{
    delete ui;
}

void Open_Leave_Window()
{
    c = new CheckLeaves();
    c->show();
}
