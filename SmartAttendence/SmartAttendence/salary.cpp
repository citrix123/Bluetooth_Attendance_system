#include "salary.h"
#include "ui_salary.h"
#include <QDebug>
#include <QSqlQuery>
#include "widget.h"
#include "Database.h"

Salary *s;
QString Query;

Salary::Salary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Salary)
{
    ui->setupUi(this);
}

Salary::~Salary()
{
    delete ui;
}

void Open_Salary_Window()
{
    s = new Salary();
    s->show();
}

void Salary::on_Id_editingFinished()
{
    //Get data for salary
//    select count(*) from Attendence_Info WHERE (Slot1 = '1' OR Slot2 = '1') AND ( Main_Attendence != '1' OR Main_Attendence IS NULL )
    QSqlQuery q;
    QString a;
    Query = "select count(*) from Attendence_Info WHERE (Slot1 = '";
    Query += ui->Id->text().toStdString().c_str() + QString("' OR Slot2 = '");
    Query += ui->Id->text().toStdString().c_str() + QString("') AND ( Main_Attendence != '");
    Query += ui->Id->text().toStdString().c_str() + QString("' OR Main_Attendence IS NULL )");
    qDebug()<<Query;
    Open_Database();
    db.open();

    q.exec(Query);

    while(q.next())
    {
        qDebug()<<q.value(0).toInt();
        a = "HalfDays : " ;
        a += q.value(0).toInt();
        qDebug()<<a;
        ui->HalfDays->setText(a);

    }


}
