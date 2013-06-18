#ifndef LEXER_H
#define LEXER_H
#include <boost/tokenizer.hpp>
#include "TableSymbols.h"
typedef std::string stream;
typedef std::string streamOut;
typedef std::string streamIn;
class Lexer
{
    public:
        Lexer();
        Lexer(TableSymbols ReadTable)
            :ml_TableSymbols(ReadTable)
        {
        }
        streamOut EraseStream(streamIn);

    private:
       TableSymbols ml_TableSymbols;
};

#endif // LEXER_H
