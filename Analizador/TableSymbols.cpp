#include "TableSymbols.h"
ExitS TableSymbols::getBasicSymbol()const
{
    const sizeT MinTam=2;
    ExitS exit;
    for(IC TSI=mts_IDS.begin();TSI!=mts_IDS.end();++TSI)
    {
        Symbol a=TSI->first;
        if(a.size()<MinTam)
        {
            exit.push_back(a.c_str()[0]);
        }
    }
    return exit;
}
