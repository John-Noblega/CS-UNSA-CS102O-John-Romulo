#include "operation.h"

tableOper* Operation::m_listOper = initOper();
tableOp* Operation::m_listOp = initOp();

/**
 * @brief Operation::Operation
 * @param op es el simbolo de la operacion
 * @param r es el puntero a un Node derecho(un operando derecho)
 * @param l es el puntero a un NOde izquierdo (un operando izquierdo)
 */
Operation::Operation(const string& op,Node* r,Node* l):m_right(r), m_left(l), m_op(op)
{
    m_oper = (*m_listOper)[m_op];// una vez creado tendra su operacion
    m_ope = (*m_listOp)[m_op];
}

tableOper* Operation::initOper()
{
    tableOper* temp = new tableOper;
    (*temp)["^"] = new PriorityFun(&pot,5);
    (*temp)["*"] = new PriorityFun(&mult,4);
    (*temp)["/"] = new PriorityFun(&divide,3);
    (*temp)["+"] = new PriorityFun(&add,2);
    (*temp)["-"] = new PriorityFun(&deduct,1);
    (*temp)["("] = new PriorityFun(0,0);
    return temp;
}

tableOp* Operation::initOp()
{
    tableOp* temp = new tableOp;
    //cargo las funciones usar, dandole su prioridad, numero de parametros
    (*temp)["^"] = new funCom(&pot,5,2,true);
    (*temp)["*"] = new funCom(&mult,4,2,true);
    (*temp)["/"] = new funCom(&divide,3,2,true);
    (*temp)["+"] = new funCom(&add,2,2,true);
    (*temp)["-"] = new funCom(&deduct,1,2,true);
    (*temp)["("] = new funCom(0,0,0,false);
    return temp;
}

tValue Operation::eval()
{
    return (*get<0>(*m_ope))(m_left->eval(), m_right->eval());
}

Operation::~Operation(){}
