#ifndef OPERATION_H
#define OPERATION_H

#include "Expresion.h"
#include "inclusions.h"
#include <string>
#include <map>

using namespace mathFun;
typedef map<string,ptrFun> tableFun;

class Operation: public Expresion
{
    public:
        Operation(Expresion*,Expresion*, const string&);
        static tableFun initFun();
        virtual tValue eval();
        virtual ~Operation();
    protected:
    private:
        Expresion *m_right;
        Expresion *m_left;
        string m_op;
        static tableFun m_listFun;
};


#endif // OPERATION_H
