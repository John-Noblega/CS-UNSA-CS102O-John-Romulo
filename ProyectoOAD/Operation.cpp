#include "Operation.h"

tableFun Operation::m_listFun = initFun();
Operation::Operation(Expresion* r,Expresion* l,const string& op):m_right(r), m_left(l), m_op(op){}

tableFun Operation::initFun()
{
    tableFun temp;
    temp["+"] = add;
    temp["-"] = deduct;
    temp["*"] =mult;
    temp["/"] = divide;
    temp["^"] = pot;
    return temp;
}

tValue Operation::eval()
{
    return m_listFun[m_op](m_right->eval(),m_left->eval());
}

Operation::~Operation()
{
    //dtor
}
