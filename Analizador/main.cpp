#include <iostream>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include "TableSymbols.h"
using namespace std;
using namespace boost;

int main(int, char**)
{
    TableSymbols ZZ;
    ZZ.AddSymbol("=");
    ZZ.AddSymbol("+");
    ZZ.AddSymbol("-");
    ZZ.AddSymbol("*");
    ZZ.AddSymbol("/");
    ZZ.AddSymbol("^");
    ZZ.AddSymbol("Seno");
    ZZ.AddSymbol("(");
    ZZ.AddSymbol(")");
    string text = "=4*SENO(30*PI()/180)";
    vector<string> A;
    char_separator<char> sep(ZZ.getBasicSymbol().c_str());
    tokenizer<char_separator<char>> tokens(text, sep);
    for (const auto& t : tokens) {
        A.push_back(t);
    }
    for(unsigned i=0;i<A.size();++i)
        cout<<A[i]<<" ";
}
