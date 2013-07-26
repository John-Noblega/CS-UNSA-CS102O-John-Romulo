#include "cell.h"

#ifndef LEXER_H
#define LEXER_H

#include "operation.h"
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <stack>
#include <stdlib.h>
#include "mastrize.h"
#include "constant.h"

using namespace std;

/**
 * @brief listOper es un tipo de dato formado por una pila de punteros a Node (podra servir para tener un conjunto de operaciones en un solo lugar)
 */
typedef stack<Node*> listOper;

/**
 *hara referencia de la clase Celda para resolver la abstraccion y su referencia circular
 */
class Cell;
/**
 * @brief The Lexer class esta clase traducira un string de una operacion combinada, para su resolucion
 */
class Lexer
{
    public:
        Lexer(){}
        /**
         * @brief Lexer permitira recibir un matriz sobre la cual se operara y un string que representa la operacion ingresada
         */
        Lexer( matrizE<Cell>*, Cell*, const string&);
        /**
         * @brief analyze traduce el string de entrada, lo hace en funcion de la Matriz y sus valores y usa los derivados de la Node Class
         * @return en caso de lograr evaluar satisfactoriamente retorna true de lo contrario false
         */
        bool analyze();

        inline void setExpre(const string& newExp){m_input=newExp; m_sizeInput = m_input.size();}
        /**
         * @brief initOperinicializa las operaciones a usar
         */
        void initOper();
        //listOperations getOutput()const{return m_output;}
        /**
         * @brief isNumber determinara si un char representa o no un numero
         * @param val es el chara a evaluar
         * @return retorna true en caso si lo sea un numero, de lo contrario false
         */
        inline bool isNumber(char val){return val>='0' && val<='9';}

        /**
         * @brief isLetterMay determinara si un char es o no una lera Mayuscula
         * @param val es el char a evaluar
         * @return retorna true o false en caso sea o no una letra mayuscula
         */
        inline bool isLetterMay(char val){return val>='A' && val<='Z';}

        /**
         * @brief isLetterMin determinara si un char es o no una lera Minuscula
         * @param val es el char a evaluar
         * @return retorna true o false en caso sea o no una letra minuscula
         */
        inline bool isLetterMin(char val){return val>='a' && val<='z';}
        /**
         * @brief isLetter determina si es una letra o no, ya sea mayuscula o minuscula
         * @param val char a evaluar
         * @return retorna tru o false, de ser o no una letra
         */
        inline bool isLetter(char val){return isLetterMay(val) || isLetterMin(val);}

        /**
         * @brief isParent determinara si un char es o no un parentesis
         * @param val char a evaluar en la funcion
         * @return etorna true en caso de ser un paraentesis o false de lo contrario
         */
        inline bool isParent(char val){return val == '(' || val == ')';}

        /**
         * @brief LetterToInt transforma un string a numero, simempre que este sea un conjuno de letras
         * @param input es el string conformado por letras
         * @param size es el tamaño de input
         * @return retorna un entero que representa el valor numerico de dicha palabra
         */
        int LetterToInt(string, const unsigned int);
        /**
         * @brief Lexer::posCell obtendra la direccion de memoria de Cell en la posicion indicada
         * @param posR es un string de numeros que indica la fila en la matriz
         * @param posC es un string de letras que indica la columna en la matriz
         * @return la direccion de memoria de Cell en caso de no existir la crea con valor cero
         */
        Cell* posCell(string&,string&);
        /**
         * @brief isOper
         * @return
         */
        bool isOper(string);
        /**
         * @brief outNumber creara un Constant usando los numeros que encuentra en input
         * @param input es un string que contendra los valores numericoas que deseamos sacar
         * @param pos es la posicion a partir del cual evaluemos a input
         * @param size es el tamanño maximo de input
         * @return retorna la direccion de memoria del Constant creado
         */
        Constant* outNumber(const string& , unsigned int& , const unsigned int);

        /**
         * @brief outOper creara un objeto Operation a partir de input y simbolos que encuentre
         * @param input es el sring a evaluar para encontrar el simbolo
         * @param pos es la posicion a partir del cual empezara a evaluar
         * @param size es el tamaño maximo de input
         * @return retornara la direccion de memoria de el Operation creado
         */
        Operation* outOper(const string&, unsigned int& pos, const unsigned int);

        /**
         * @brief outParenpermite crear un objeto Operation con un parentesisi de abertura
         * @param input string a evaluar
         * @param pos es la posicion donde se encuentra el parentesis
         * @param size tamaño maximo de input
         * @param countPar es el numero de parentesis actual
         * @return retorna una Operation conformada por un parentesis
         */
        Operation* outParen(const string&, unsigned int&, const unsigned int, unsigned int&);
        /**
         * @brief searchCloseParen sacara los elementos de la pila hasta encontrar un parentesis de abertura
         * @param sOper es la ila de operaciones
         * @param sOperand es la pila de operandos
         * @return  retornara true en caso de haber encontrado satisfactoriamente el parentesis de abertura
         */
        bool searchCloseParen(stack<Operation*>&, stack<Node*>&, unsigned int&);
        /**
         * @brief outFun permitira encapsular una operacion aartir de su simbolo
         * @return retorna la direccion de Operation
         */
        Operation* outFun(const string&, const string&, unsigned int&);
        /**
         * @brief outFun permitira encapsular una operacion aartir de su simbolo
         * @return retorna la direccion de Operation
         */
        Operation* outFun(const string&, unsigned int&, const unsigned int);
        /**
         * @brief outCell permitira encapsular una celda encontrada en el string, de no existir la celda la crea en la Mtriz
         * @return una celda encontrada o creada
         */
        Node* outCell(const string&, unsigned int&, const unsigned int);
        /**
         * @brief getResp devuelve la respuesta, producto de la evaluacion del string
         * @return un Node, que reresenta el ultimo valor de la pila de evaluacion
         */
        Node* getResp(){return resp;}
        virtual ~Lexer();
    protected:
    private:
        matrizE<Cell>* m_matiz;
        Cell* m_cellAct;
        string m_input;
        unsigned int m_sizeInput;
        Node* resp;
        //listOperations m_output;
        static list<string> m_listOp;

        /**
         * @brief Oper_Stack evaluara si una operacion es esta en condiciones de eser ejecutada
         * @param op es la operacion a evaluarse con respecto a la pila de operaciones
         * @param sOper es la pila de operaciones
         * @param sOperand es la pila de operandos
         * @return retorna true en caso de que a oparcion se ingresara a la pila
         */
        bool Oper_Stack(Operation*, stack<Operation*>&, stack<Node*>&);
        /**
         * @brief Oper_Stack terminara de ejecutar todas la funciones restantes de las pilas
         * @param sOper es una pila de operaciones
         * @param sOperand es una pila de operandos
         * @return retorna true en caso de que dejara vacias, satisfactoriamente la pila de operaciones y false en caso contrario
         */
        bool Oper_Stack(stack<Operation*>&, stack<Node*>&);
};

#endif // LEXER_H
