

#include <string>
#include <list>
#include "Cell.h"
#include <iostream>

using namespace std;

namespace toolsParser
{
    struct Token
    {
        unsigned m_tMember;
        tValue m_value;
        Cell *m_cell;
        int pp;
        string m_op;
       // Token(tValue value, int p = 0, string op= ""):m_value(value), pp(p), m_op(op)
       // {
        //    cout<<"1-Token value: "<<value<<" Cell: "<<pp<<" Op: "<<op<<endl;
       // }
        Token(tValue value, Cell* cell= 0, string op= "N"):m_value(value), m_cell(cell), m_op(op)
        {
            cout<<"2-Token value: "<<value<<" Cell: ---"<<" Op: "<<op<<endl;
        }

    };


}

