#include "retrivewindow.h"
#include "ui_retrivewindow.h"
#include "widget.h"
#include "Database.h"

RetriveWindow *r;
RetriveWindow::RetriveWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RetriveWindow)
{
    ui->setupUi(this);
}

RetriveWindow::~RetriveWindow()
{
    delete ui;
}

void Open_Retrive_Window()
{
    r = new RetriveWindow();
    r->show();
}
