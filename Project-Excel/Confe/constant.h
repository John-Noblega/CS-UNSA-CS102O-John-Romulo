#ifndef CONSTANT_H
#define CONSTANT_H

#include "node.h"


/**
 * @brief The Constant class esta clase ohija de Node solo definira un valor numerico
 */
class Constant: public Node
{
    public:
        /**
         * @brief Constant este constructor solo obtendra el valor numerico del valor a representar
         */
        Constant(const tValue&);
        /**
         * @brief eval solo evalua el valor que contien el objeto
         * @return el valor numerico del numero que representa
         */
        inline virtual tValue eval(){return m_value; }
    private:
        /**
         * @brief m_value es el valor numerico que el objeto representa
         */
        tValue m_value;
};

#endif // CONSTANT_H
