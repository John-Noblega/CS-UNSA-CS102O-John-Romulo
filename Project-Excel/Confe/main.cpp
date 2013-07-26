#include "interface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    matrizE<string> matrix;
    matrix.insert_node("hola",8,8);
    matrix.insert_node(" como",5,5);
    matrix.insert_node(" estas",3,3);
    matrix.insert_node("alexis",3,5);
    matrix.insert_node("mujajaja",1,8);
    matrix.insert_node("lololo",8,8);
    matrix.insert_node("lalalaal",8,1);





    QApplication a(argc, argv);
    interface w;
    w.show();
    
    return a.exec();
}
