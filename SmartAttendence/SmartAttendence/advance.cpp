#include "advance.h"
#include "ui_advance.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "widget.h"
#include "Database.h"
#include <QDate>
#include <QTime>
#include <QSqlQuery>
#include <QFile>
#include <QMessageBox>
#include "salary.h"
QSqlQueryModel *model1;
Advance *a;
QString q;
bool tableClicked = false;
bool date = false, Print_Attendance = false;
bool Leave_Type = false,leaveSlot = false , Leave = false;
Leaves_Status Leaves;
Advance::Advance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Advance)
{
    ui->setupUi(this);
    ui->Id->setPlaceholderText("Please Enter Id..");
    ui->name->setPlaceholderText("Please Enter Name..");
    ui->proceed->setVisible(false);

    ui->tableView->setVisible(false);
    ui->Datefrom->setVisible(false);
    ui->DateTo->setVisible(false);
    ui->EL->setVisible(false);
    ui->Id->setVisible(false);
    ui->LeaveType->setVisible(false);
    ui->Leave_Slots->setVisible(false);
    ui->LWP->setVisible(false);
    ui->name->setVisible(false);
    ui->TimeTo->setVisible(false);
    ui->TimeFrom->setVisible(false);
    ui->CL->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->TL->setVisible(false);
    ui->Datefrom->setDate(QDate::currentDate());
    ui->DateTo->setDate(QDate::currentDate());
}

Advance::~Advance()
{
    delete ui;
}

void Open_Advance_Window()
{
    a = new Advance();
    a->show();
}

void Advance::on_comboBox_activated(int index)
{
    QString q;
    if(index==0)
    {
        qDebug()<<"working..";
    }
    if(index==2)
    {
        ui->tableView->setVisible(true);
        qDebug()<<"cheking present faculty";
        qDebug()<<QTime::currentTime().toString("HH:mm:ss");
        qDebug()<<QDate::currentDate().toString("yyyy-MM-dd");
//        check for time
        QTime t(10,00), t2(13,00), t3(16,00);
        if(QTime::currentTime().operator >=(t) || QTime::currentTime().operator <=(t2))
        {
            qDebug()<<"working";
            qDebug()<<"Query intitializing";
            q = "Select Attendence_Info.Slot1, Faculty_Info.Name From Attendence_Info INNER JOIN Faculty_Info where Attendence_Info.Slot1 = Faculty_Info.Id AND Date = CURDATE()";
            qDebug()<<q;
            Open_Database();
            db.open();
            model1 = new QSqlQueryModel();
            model1->setQuery(q);
            ui->tableView->setModel(model1);
        }
        else if(QTime::currentTime().operator >=(t2) || QTime::currentTime().operator <=(t3))
        {
            qDebug()<<"working";
            qDebug()<<"Query intitializing";
            q = "Select Attendence_Info.Slot2, Faculty_Info.Name From Attendence_Info INNER JOIN Faculty_Info where Attendence_Info.Slot1 = Faculty_Info.Id Date = CURDATE()";
            qDebug()<<q;
            Open_Database();
            db.open();
            model1 = new QSqlQueryModel();
            model1->setQuery(q);
            ui->tableView->setModel(model1);
        }
    }
    else if(index == 3)
    {
        ui->tableView->setVisible(1);
        q = "select Id, Name from Faculty_Info where Id NOT IN (select Slot1 from Attendence_Info where Date = CURDATE())";
        qDebug()<<q;
        Open_Database();
        db.open();
        model1 = new QSqlQueryModel();
        model1->setQuery(q);
        ui->tableView->setModel(model1);
    }
    else if(index == 5)
    {
        qDebug()<<"in Faculty Leave request..";
        ui->Option->setText("Faculty Leave Request");
        ui->proceed->setVisible(true);
        ui->comboBox->setVisible(false);
        ui->tableView->setVisible(false);
        ui->Datefrom->setVisible(true);
        ui->DateTo->setVisible(true);
        ui->EL->setVisible(true);
        ui->Id->setVisible(true);
        ui->LeaveType->setVisible(true);
        ui->Leave_Slots->setVisible(true);
        ui->LWP->setVisible(true);
        ui->name->setVisible(true);
        ui->TimeTo->setVisible(true);
        ui->TimeFrom->setVisible(true);
        ui->CL->setVisible(true);
        ui->textEdit->setVisible(true);
        ui->TL->setVisible(true);

    }
    else if(index==6)  //print monthly attendence
    {
        ui->Option->setText("Attendence Records");
        ui->comboBox->setVisible(false);
        ui->Id->setVisible(true);
        ui->Datefrom->setVisible(true);
        ui->DateTo->setVisible(true);
        ui->Datefrom->setDate(QDate::currentDate());
        ui->Datefrom->setGeometry(90,85,110,27);
        ui->DateTo->setGeometry(370,85,110,27);
        ui->tableView->setVisible(true);
        ui->TimeFrom->setVisible(true);
        ui->TimeTo->setVisible(true);
        ui->TimeTo->setGeometry(270,85,77,17);
        ui->TimeFrom->setGeometry(30,85,57,17);
        ui->proceed->setVisible(true);
        Print_Attendance = true;

      }
    else if(index == 7) //Salary calculator
    {
        Open_Salary_Window();
    }
}

void Advance::on_back_clicked()
{
    qDebug()<<"back clicked";
    ui->comboBox->setVisible(!true);
    ui->proceed->setVisible(!true);
    ui->comboBox->setVisible(!false);
    ui->tableView->setVisible(false);
    ui->Datefrom->setVisible(!true);
    ui->DateTo->setVisible(!true);
    ui->EL->setVisible(!true);
    ui->Id->setVisible(!true);
    ui->LeaveType->setVisible(!true);
    ui->Leave_Slots->setVisible(!true);
    ui->LWP->setVisible(!true);
    ui->name->setVisible(!true);
    ui->TimeTo->setVisible(!true);
    ui->TimeFrom->setVisible(!true);
    ui->CL->setVisible(!true);
    ui->textEdit->setVisible(!true);
    ui->TL->setVisible(!true);
    ui->savetofile->setVisible(false);
}

void Advance::on_Id_returnPressed()
{

}

void Advance::on_Id_editingFinished()
{
    qDebug()<<"Hii world";
    Open_Database();
    db.open();
    QSqlQuery query;
    QString q;
    q = "Select Name , Credit_Leaves, Total_Leaves, Earned_Leaves, LWP from Faculty_Info where Id = '";
    q = q + ui->Id->text() + QString("'");

    Leaves.R_ID = ui->Id->text();
    qDebug()<<q;
    query.exec(q);
    while(query.next())
    {
        qDebug()<<query.value(0).toString();
        ui->name->setText(query.value(0).toString());
        q = "Credit Leaves : " + query.value(1).toString();
        ui->CL->setText(q);
        q = "Total Leaves : " + query.value(2).toString();
        ui->TL->setText(q);
        q = "Earned Leaves : " + query.value(3).toString();
        ui->EL->setText(q);
        q = "LWP :" + query.value(4).toString();
        ui->LWP->setText(q);
        Leaves.R_CL = query.value(1).toInt();
        Leaves.R_EL = query.value(3).toInt();
        Leaves.R_TL = query.value(2).toInt();
        Leaves.R_LWP = query.value(4).toInt();

    }
}

void Advance::on_name_editingFinished()
{
    Open_Database();
    db.open();
    QSqlQuery query;
    QString q;
    q = "Select Id , Credit_Leaves, Total_Leaves, Earned_Leaves, LWP from Faculty_Info where Name ='";
    q = q + ui->name->text() + QString("'");
    qDebug()<<q;
    query.exec(q);
    while(query.next())
    {

        qDebug()<<query.value(1).toInt();
        Leaves.R_ID = query.value(0).toInt();
        Leaves.R_CL = query.value(1).toInt();
        Leaves.R_EL = query.value(3).toInt();
        Leaves.R_TL = query.value(2).toInt();
        Leaves.R_LWP = query.value(4).toInt();
        qDebug()<<query.value(0).toString();

        ui->Id->setText(query.value(0).toString());
        q = "Credit Leaves : " + query.value(1).toString();
        ui->CL->setText(q);

//        qDebug()<<b.R_CL;
        q = "Total Leaves : " + query.value(2).toString();
        ui->TL->setText(q);
        q = "Earned Leaves : " + query.value(3).toString();
        ui->EL->setText(q);
        q = "LWP :" + query.value(4).toString();
        ui->LWP->setText(q);

    }
}

void Advance::on_Leave_Slots_currentIndexChanged(int index)
{
    Open_Database();
    db.open();
    QSqlQuery query;
    Leave = true;
    QString q;
        if(date)
        {
        int Diff = ui->DateTo->date().daysTo(ui->Datefrom->date());
        qDebug()<<Diff;

        switch (index) {
        case 1:
            leaveSlot = true;
                qDebug()<<"Leave Category : Credit Leave selected";

                //cut the leaves from Credit Leaves
                if(Leaves.R_CL-Diff >=0)
                {

                    qDebug()<<"You are able to cut Credit Leaves";
                    q = "Update Faculty_Info set Credit_Leaves = Credit_Leaves-";
                    q += QString::number(Diff) + QString(" where Id = '") + Leaves.R_ID.toStdString().c_str() + QString("'");
                    qDebug()<<q;
                    query.exec(q);
                }
                else
                {
                    qDebug()<<"Try another sections of Leaves";
                }
                break;


        case 2:
            leaveSlot = true;
            if(Leaves.R_EL - Diff >=0)
            {
                qDebug()<<"You are able to cut Earned Leaves";
                q = "Update Faculty_Info set Earned_Leaves = Earned_Leaves-";
                q += QString::number(Diff) + QString(" where Id = '") + Leaves.R_ID.toStdString().c_str() + QString("'");
                qDebug()<<q;
                query.exec(q);
            }
            else
            {
                qDebug()<<"Try Another section of leaves";
            }
            break;

                // and update status
        case 3:
            leaveSlot = true;
            q = "Update Faculty_Info set LWP = LWP+";
            q += QString::number(Diff) + QString(" where Id = '") + Leaves.R_ID.toStdString().c_str() + QString("'");
            qDebug()<<q;
            query.exec(q);
            break;
        }
    }
}


void Advance::on_LeaveType_currentIndexChanged(int index)
{
    QString q;

    if(index ==1)
    {
        qDebug()<<"Applying for half Day";
        ui->Datefrom->setEnabled(false);
        ui->DateTo->setEnabled(false);
        ui->Leave_Slots->setEnabled(false);
        Leave_Type = true;
    }
    else if(index == 2)
    {
        ui->Leave_Slots->setEnabled(false);
    }

}

void Advance::on_proceed_clicked()
{
    QSqlQuery query;
    QString q;
    Open_Database();
    db.open();
    //insert into Leave_Info values();
    if(Leave_Type)
    {
        q = "Insert into Leave_Info values ('";
        q += Leaves.R_ID + QString("',");
        q += QString("'Half Day','") + QDate::currentDate().toString("yyyy-MM-dd") + QString("','");
        q += QDate::currentDate().toString("yyyy-MM-dd") + QString("','");
        q += QString("LWP','") + ui->textEdit->toPlainText() + QString("')");
        qDebug()<<q;

        query.exec(q);

    }
    else if(!Leave_Type&&leaveSlot&&Leave)
    {
        q = "Insert into Leave_Info values ('";
        q += Leaves.R_ID + QString("',");
        q += QString("'Full Day','") + ui->Datefrom->date().toString("yyyy-MM-dd") + QString("','");
        q += ui->DateTo->date().toString("yyyy-MM-dd") + QString("','");
        q += ui->Leave_Slots->currentText() + QString("','") + ui->textEdit->toPlainText() + QString("')");
        qDebug()<<q;
        query.exec(q);
        q = "Select Name , Credit_Leaves, Total_Leaves, Earned_Leaves, LWP from Faculty_Info where Id = '";
        q = q + ui->Id->text() + QString("'");
        qDebug()<<q;
        query.exec(q);
        while(query.next())
        {
            qDebug()<<query.value(0).toString();
            ui->name->setText(query.value(0).toString());
            q = "Credit Leaves : " + query.value(1).toString();
            ui->CL->setText(q);
            qDebug()<<q;
            q = "Total Leaves : " + query.value(2).toString();
            ui->TL->setText(q);
            qDebug()<<q;
            q = "Earned Leaves : " + query.value(3).toString();
            ui->EL->setText(q);
            qDebug()<<q;
            q = "LWP :" + query.value(4).toString();
            ui->LWP->setText(q);
            qDebug()<<q;


        }
    }
    else if(Print_Attendance) //print Attendence Combo box
    {
        q = "SELECT Faculty_Info.Id AS Id, COUNT(*) AS total FROM Faculty_Info AS Faculty_Info INNER JOIN Attendence_Info AS Attendence_Info ON Faculty_Info.Id = Attendence_Info.Main_Attendence AND Date between '";
        //q += "AND Date between '2013-10-28' AND '2014-01-28' GROUP BY Faculty_Info.Id"
        q += ui->Datefrom->date().toString("yyyy-MM-dd") + QString("' AND '");
        q += ui->DateTo->date().toString("yyyy-MM-dd") + QString("' GROUP BY Faculty_Info.Id ");
        qDebug()<<q;

        Open_Database();
        db.open();
        model1 = new QSqlQueryModel();
        model1->setQuery(q);
        ui->tableView->setModel(model1);
    }
    else
    {
        qDebug()<<"Check the unfilled boxes";
    }
//    Print_Attendance = false;

}

void Advance::on_Datefrom_dateChanged(const QDate &dat)
{
    qDebug()<<"Active slot working...";
    date = true;
    ui->Leave_Slots->setEnabled(true);
}

void Advance::on_tableView_doubleClicked(const QModelIndex &index)
{

    qDebug()<<index.data().toString();
    QString query;
    q =index.data().toString();
    qDebug()<<q.toStdString().c_str();
    query = "Select Date AS FullAttendenceDates from Attendence_Info where Main_Attendence ='";
    query += q + QString("'");
    qDebug()<<query;
    model1 = new QSqlQueryModel();
    model1->setQuery(query);
    ui->tableView->setModel(model1);
    tableClicked = true;
//    QFile file("/home/")i


}

void Advance::on_savetofile_clicked()
{
    qDebug()<<"TableClicked = "<<tableClicked;
    QSqlQuery q1;
    QString Q, query;
    if(!tableClicked)
    {
        //for all counts of all faculties
        query = "/home/rahul/SmartAttendence/AttendenceSheet";
        query += QTime::currentTime().toString().toStdString().c_str() + QString(".csv");

        qDebug()<<query;


        QFile file(query);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        if(Print_Attendance) //print Attendence Combo box
            {
                Q = "SELECT Faculty_Info.Id AS Id, COUNT(*) AS total FROM Faculty_Info AS Faculty_Info INNER JOIN Attendence_Info AS Attendence_Info ON Faculty_Info.Id = Attendence_Info.Main_Attendence AND Date between '";
                //q += "AND Date between '2013-10-28' AND '2014-01-28' GROUP BY Faculty_Info.Id"
                Q += ui->Datefrom->date().toString("yyyy-MM-dd") + QString("' AND '");
                Q += ui->DateTo->date().toString("yyyy-MM-dd") + QString("' GROUP BY Faculty_Info.Id ");
                qDebug()<<Q;

                Open_Database();
                db.open();
                q1.exec(Q);

                while(q1.next())
                {
                    out<<q1.value(0).toString().toStdString().c_str();
                    out<<q1.value(1).toString().toStdString().c_str()<<"\n";
                }



         }
    }

    else if(tableClicked==true)
    {
        //for specific id
        query = "/home/rahul/SmartAttendence/AttendenceId";
        query += q + QTime::currentTime().toString().toStdString().c_str() + QString(".csv");
        qDebug()<<query;
        Q = "Select Date from Attendence_Info Where Main_Attendence = '";
        Q += q + QString("'");
        qDebug()<<Q;
        Open_Database();
        db.open();
        q1.exec(Q);
//        QFile file(query);
        QFile file(query);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
//        out<<"Id = "<<q<<"\n";
        while(q1.next())
        {
            out<<q1.value(0).toString().toStdString().c_str()<<"\n";
//            out<<q1.value(1).toString().toStdString().c_str()<<"\n";
        }
        QMessageBox::information(0, "Success", "Saved in File");
    }

}
