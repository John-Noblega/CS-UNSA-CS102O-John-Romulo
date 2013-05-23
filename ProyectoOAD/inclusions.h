
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
    inline tValue sin(tValue v1, tValue v2=0){return sin(v1);}
    inline tValue cos(tValue v1, tValue v2=0){return cos(v1);}


    struct PriorityFun{
        int m_priority;
        ptrFun m_fun;
        PriorityFun(const int& priority, ptrFun fun):m_priority(priority), m_fun(fun){}
    };
    static map<int,int> l;




}

