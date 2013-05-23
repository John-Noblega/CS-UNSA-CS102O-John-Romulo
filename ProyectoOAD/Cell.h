#ifndef CELL_H
#define CELL_H

#include "Expresion.h"
#include "inclusions.h"
#include <list>

class Cell: public Expresion
{
    public:
        Cell();
        virtual tValue eval();
        virtual ~Cell();
    protected:
    private:
        list<Expresion*> m_depended;

};

#endif // CELL_H
