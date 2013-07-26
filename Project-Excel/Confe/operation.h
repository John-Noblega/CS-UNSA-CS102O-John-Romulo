#ifndef OPERATION_H
#define OPERATION_H

#include "node.h"
#include "inclusions.h"
#include <string>
#include <map>
#include <iostream>
#include <tuple>
#include <unordered_map>

using namespace std;
using namespace mathFun;
typedef map<string,ptrFun> tableFun;
typedef map<string,PriorityFun*> tableOper;

typedef tuple<ptrFun, const unsigned int, const unsigned int, bool> funCom;
typedef unordered_map<string, funCom*> tableOp;

/**
 * @brief The Operation class esta clase hija de Node representara a una operacion binaria o unaria dependiendo del simbolo que le sea dado
 */

class Operation: public Node
{
    public:
        /**
         * @brief Operation recibira un strign que es el simbolo y dos operandos que son punteros a Nodes
         */
        Operation(const string&, Node* =0, Node* =0);
        /**
         * @brief operator < evalara que operacion es menor a la otra
         * @param op2 es el segundo operando
         * @return retorna un bool en caso l primer operador es menor al otro
         */
        virtual inline bool operator <(const Operation& op2){return  m_oper->m_priority < op2.m_oper->m_priority;}
        /**
         * @brief initOper inicializa todas las operaciones que tendran todos las instancias de esta clase
         * @return retorna una lista de operaciones por defecto
         */
        static tableOper* initOper();
        static tableOp* initOp();
        /**
         * @brief eval evalua la operacion efectuada enter los dos operancos
         * @return retorna el valor numerico de dicha operacion
         */
        virtual tValue eval();

        /**
         * @brief setRight modifica el valor de m_right
         * @param nodeR es el nuevo Node a ser asignado a m_right
         */
        inline void setRight(Node* nodeR){m_right = nodeR;}
        /**
         * @brief setLeft modifica el valor de m_left
         * @param nodeL es el nuevo Node a ser asignado a m_left
         */
        inline void setLeft(Node* nodeL){m_left = nodeL;}
        /**
         * @brief setConstants modificara el valor de ambos operandos
         * @param nodeL sera el nuevo Node izquierdo
         * @param nodeR sera el nuevo Nde derecho
         */
        void setConstants(Node* nodeL, Node* nodeR)
        {
            setLeft(nodeL);
            setRight(nodeR);
        }

        inline string getSymbol(){return m_op;}

        virtual ~Operation();
    protected:
    private:
        /**
         * @brief m_right es un puntero a un Node que sera el operando derecho
         */
        Node *m_right;
        /**
         * @brief m_left es un puntero a un Node que sera el operando izquierdo
         */
        Node *m_left;
        /**
         * @brief m_oper sera un puntero a un PriorityFun una vez que se sepa el simbolo de la operacion
         */
        PriorityFun* m_oper;
        funCom* m_ope;
        /**
         * @brief m_op es un string que representa el simbolo de la operacion
         */
        string m_op;
        /**
         * @brief m_listOper esta un map de operaciones cuyo key son los  simbolos de la operaciones, este sera estatico para que toda instancia lo usea y este al tanto de modificaciones
         */
        static tableOper* m_listOper;
        static tableOp* m_listOp;

};


#endif // OPERATION_H

