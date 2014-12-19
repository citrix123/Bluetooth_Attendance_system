#ifndef ADVANCE_H
#define ADVANCE_H

#include <QMainWindow>

namespace Ui {
class Advance;
}

class Advance : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Advance(QWidget *parent = 0);
    ~Advance();
    
private slots:
    void on_comboBox_activated(int index);

    void on_back_clicked();

    void on_Id_returnPressed();

    void on_Id_editingFinished();

    void on_name_editingFinished();

    void on_Leave_Slots_currentIndexChanged(int index);

    void on_LeaveType_currentIndexChanged(int index);

    void on_proceed_clicked();

    void on_Datefrom_dateChanged(const QDate &dat);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_savetofile_clicked();

private:
    Ui::Advance *ui;
};
void Open_Advance_Window();

#endif // ADVANCE_H
