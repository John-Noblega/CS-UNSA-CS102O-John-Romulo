#ifndef INTERFACE_H
#define INTERFACE_H
#include<QTableWidget>
#include <QMainWindow>
#include "mastrize.h"
#include "lexer.h"

namespace Ui {
class interface;
}

class interface : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit interface(QWidget *parent = 0);
    ~interface();
    
private slots:

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::interface *ui;
    matrizE<Cell> mymatri;
};

#endif // INTERFACE_H
