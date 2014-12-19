#ifndef CHECKLEAVES_H
#define CHECKLEAVES_H

#include <QMainWindow>

namespace Ui {
class CheckLeaves;
}

class CheckLeaves : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CheckLeaves(QWidget *parent = 0);
    ~CheckLeaves();
    
private:
    Ui::CheckLeaves *ui;
};
void Open_Leave_Window();

#endif // CHECKLEAVES_H
