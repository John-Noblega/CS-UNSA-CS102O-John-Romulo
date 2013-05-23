#ifndef LEXER_H
#define LEXER_H

#include "Matrix.h"
#include "Cell.h"
#include "ToolsLexer.h"
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdlib.h>



using namespace toolsParser;


typedef list<Token*> listOperations;

class Lexer
{
    public:
        Lexer(Matrix<Cell>*,const string&);
        void analyze(listOperations&);
        void initOper();
        //listOperations getOutput()const{return m_output;}
        inline bool isNumber(char val){return val>='0' && val<='9';}
        inline bool isLetterMay(char val){return val>='A' && val<='Z';}
        inline bool isLetterMin(char val){return val>='a' && val<='z';}
        inline bool isLetter(char val){return isLetterMay(val) || isLetterMin(val);}
        inline bool isParent(char val){return val == '(' || val == ')';}
        Cell* posCell(string);
        bool isOper(string);

        virtual ~Lexer();
    protected:
    private:
        Matrix<Cell>* m_matrix;
        string m_input;
        //listOperations m_output;
        static list<string> m_listOp;

};

#endif // LEXER_H
