#ifndef NODE_H
#define NODE_H

/**
 * @brief tValue typedef que sera el valo a aceptar en Node y sus hijos
 */
typedef float tValue;

/**
 * @brief The Node class es una clase abstracta pero cuyo fin es tener un valor numerico
 */
class Node
{
    public:
        Node();
        /**
         * @brief eval es una funcion virtual pura ya que no se sabe exactamente que es Node, pero a ser redefinida por los hijos
         * @return retornara un valor numerico, una vez redefinido
         */
        virtual tValue eval()=0;

        virtual inline bool operator <(const Node&){return true;}
};
#endif // NODE_H
