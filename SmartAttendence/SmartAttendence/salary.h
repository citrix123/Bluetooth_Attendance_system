#ifndef SALARY_H
#define SALARY_H

#include <QWidget>

namespace Ui {
class Salary;
}

class Salary : public QWidget
{
    Q_OBJECT
    
public:
    explicit Salary(QWidget *parent = 0);
    ~Salary();
    
private slots:
    void on_Id_editingFinished();

private:
    Ui::Salary *ui;
};

void Open_Salary_Window();

#endif // SALARY_H
