#ifndef RETRIVEWINDOW_H
#define RETRIVEWINDOW_H

#include <QWidget>

namespace Ui {
class RetriveWindow;
}

class RetriveWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit RetriveWindow(QWidget *parent = 0);
    ~RetriveWindow();
    
private:
    Ui::RetriveWindow *ui;
};

void Open_Retrive_Window();
#endif // RETRIVEWINDOW_H
