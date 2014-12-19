#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <stdio.h>
#include <QDebug>
extern QSqlDatabase db;
extern QString Login;

struct Leaves_Status{
    int R_CL;
    int R_EL;
    int R_TL;
    int R_LWP;
    QString R_ID;
};

#endif // DATABASE_H
