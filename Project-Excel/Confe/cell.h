#ifndef CELL_H
#define CELL_H

#include "node.h"
#include "inclusions.h"
#include <list>
#include "lexer.h"
#include "mastrize.h"
#include <unordered_set>
//#include "cell.h"
using namespace std;

/**
 * @brief The Cell class esta clase hija de Node permitira representar una celda con una expresion para pasar a ser un valor numerico
 */
class Cell: public Node
{
    public:
                /**
                 * @brief Cell cosntructor por defecto
                 */
                Cell();
                Cell(string exp, matrizE<Cell>* matriz): m_expression(exp),m_matriz(matriz)
                {
                    m_lex = Lexer(matriz,this,exp);
                    m_update = false;
                    update();
                    cout<<eval()<<endl;
                    depen = 0;
                }
                Cell(tValue val, matrizE<Cell>* matriz):m_value(val),m_matriz(matriz){
                    m_lex = Lexer(matriz,this,"");
                    m_update = false;
                depen = 0;}
                void setVal(tValue  val){m_value = val;}
                void setExpr(const string& expr){
                    m_expression = expr;
                    m_lex.setExpre(expr);
                    m_update=true;
                    update();
                }
                void updateDep()
                {
                    for(Cell* i: m_depended)
                        i->update();
                }

                void update(){
                    cout<<"ejecutando"<<endl;
                       m_lex.initOper();
                       m_lex.analyze();
                       m_value = m_lex.getResp()->eval();
                       cout<<m_depended.size()<<"wertyuiosdfghjkl"<<endl;
                       m_update = false;
                  //     updateDep();

                }

                virtual tValue eval();
                virtual bool operator <(const Cell&){ return 0;}
                inline void addDependece(Cell* dep){m_depended.insert(dep); depen++;}
                virtual ~Cell();
    protected:
    private:
        string m_expression;
        unordered_set<Cell*> m_depended;
        tValue m_value;
        matrizE<Cell> *m_matriz;
        Lexer m_lex;
        bool m_update;
        int depen;
};
#endif // CELL_H

