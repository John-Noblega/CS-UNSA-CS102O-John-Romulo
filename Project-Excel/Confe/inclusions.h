#ifndef INCLUSIONS_H
#define INCLUSIONS_H


#include <stack>
#include <map>
#include <string>
#include <math.h>
using namespace std;


typedef float tValue;
typedef tValue (*ptrFun)(tValue,tValue);
typedef char expUnary;

namespace mathFun
{
    inline tValue add(tValue v1, tValue v2){return v1+v2;}
    inline tValue deduct(tValue v1, tValue v2){return v1-v2;}
    inline tValue mult(tValue v1, tValue v2){return v1*v2;}
    inline tValue divide(tValue v1, tValue v2){return v1/v2;}
    inline tValue pot(tValue v1, tValue v2){return pow(v1,v2);}
    inline tValue sqrt(tValue v1, tValue v2){return v1/v2;}
    inline tValue sin(tValue v1, tValue v2=1){return sin(v1);}
    inline tValue cos(tValue v1, tValue v2=1){return cos(v1);}


    struct PriorityFun{
        ptrFun m_fun;
        unsigned int m_priority;
        unsigned int m_param;
        bool m_inf;
        PriorityFun(ptrFun fun, const unsigned int& priority = 1, const unsigned int& param = 2, bool infijo = true)
        :m_fun(fun),m_priority(priority),m_param(param),m_inf(infijo){}
    };

    static map<int,int,int> l;
}


#endif // INCLUSIONS_H
