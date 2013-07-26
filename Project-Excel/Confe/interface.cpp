#include "interface.h"
#include "ui_interface.h"

interface::interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
}

interface::~interface()
{
    delete ui;
}


void interface::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    Cell n1(item->text().toStdString(),&mymatri);
    mymatri.insert_node(n1,item->row(),item->column());
    item->setText(QString::number(n1.eval()));
}
