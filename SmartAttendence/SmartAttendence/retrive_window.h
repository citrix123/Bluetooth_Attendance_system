#ifndef RETRIVE_WINDOW_H
#define RETRIVE_WINDOW_H

#include <QWidget>

namespace Ui {
class Retrive_Window;
}

class Retrive_Window : public QWidget
{
    Q_OBJECT
    
public:
    explicit Retrive_Window(QWidget *parent = 0);
    ~Retrive_Window();
    
private slots:
    void on_Modify_clicked();

    void on_checkleaves_clicked();

    void on_Advance_clicked();

private:
    Ui::Retrive_Window *ui;
};
void Open_Retrive_Window();

#endif // RETRIVE_WINDOW_H
