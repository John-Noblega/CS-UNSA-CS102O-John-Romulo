#ifndef TABLESYMBOLS_H
#define TABLESYMBOLS_H
#include <map>
#include <string>
class TokenInfo;
typedef unsigned int sizeT;
typedef std::string Symbol;
typedef std::string ExitS;
typedef std::map<Symbol,TokenInfo*> Table;
typedef Table::const_iterator IC;
class TableSymbols
{
    public:
        TableSymbols()
            :mts_total(0)
        {
        }
        TableSymbols(const TableSymbols &Oclone)
            :mts_IDS(Oclone.mts_IDS),mts_total(Oclone.mts_total)
        {
        }
        inline TokenInfo * operator[](Symbol Val){return mts_IDS[Val];}
        inline void operator =(TableSymbols copyTableS)
        {
            mts_IDS=copyTableS.mts_IDS;
            mts_total=copyTableS.mts_total;
        }
        inline void AddSymbol(Symbol newSymbol)//,TokenInfo*& newTI=NULL)
        {
            mts_IDS[newSymbol]=0;
            mts_total++;
        }
        void EraseSymbol(Symbol);
        ExitS getBasicSymbol()const;
    private:
        Table mts_IDS;
        sizeT mts_total;
};

#endif // TABLESYMBOLS_H
