#ifndef OPERAND_H
#define OPERAND_H

#include "Expresion.h"



class Operand: public Expresion
{
    public:
        Operand(const tValue&);
        inline virtual tValue eval(){return m_value; }
        virtual ~Operand();
    protected:
    private:
        tValue m_value;
};

#endif // OPERAND_H
