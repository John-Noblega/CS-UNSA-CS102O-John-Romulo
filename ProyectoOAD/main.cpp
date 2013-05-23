#include <iostream>

#include "Matrix.h"
#include <cstring>
#include "Lexer.h"
#include "Expresion.h"
#include "Operand.h"



using namespace std;


using namespace mathFun;

int main()
{
    Matrix <Cell>m;
    Cell cc;
    m.insertValue(2,1,cc);
    Lexer l(&m,"12+A4+5");
    l.initOper();
    list<Token*> v;
    l.analyze(v);
    bool correcto = v.empty();
    if(!correcto)
        cout<<"expresion correcta"<<endl;
    else
        cout<<"expresion incorercta"<<endl;
        cout<<v.size()<<endl;

    bool e = 'A'<='9' && 'A'>='0';
    cout<<pow(2,0)<<endl;
    cout<<e<<endl;



    return  0;
}
