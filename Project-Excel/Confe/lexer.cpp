#include "lexer.h"

list<string> Lexer::m_listOp(5);

/**
 * @brief Lexer::Lexer
 * @param matrix matriz en funcion de la cual se operara y monitoeara valores
 * @param input es el string ingresao por el usuario, que representa a las operaciones que desea realizar ej.: "1+2*A3"
 */
Lexer::Lexer(matrizE<Cell> *matrix,Cell* cellAct, const string& input):m_matiz(matrix),m_cellAct(cellAct),m_input(input),m_sizeInput(input.size()){}

void Lexer::initOper()
{
    m_listOp.push_back("+");
    m_listOp.push_back("-");
    m_listOp.push_back("*");
    m_listOp.push_back("/");
    m_listOp.push_back("^");
    //m_listOp.push_back("(");
}

/**
 * @brief Lexer::isOper evalua si el string entregado, representa una operacion o funcion
 * @param val es un string que sera evaluado
 * @return retorna verdadero de ser val una operacion o funcion
 */
bool Lexer::isOper(string val)
{
    if(val=="")
        return false;
    for(list<string>::iterator it=m_listOp.begin(); it != m_listOp.end();it++)
        if((*it) == val)
            return true;
    return false;
}

int Lexer::LetterToInt(string input, const unsigned int size)
{
    if(size==1)
        return (int)(input[0])-64 ;
    return ((int)(input[0])-64)*pow(25,size-1) + LetterToInt(input.substr(1,size-1),size-1);
}

Constant* Lexer::outNumber(const string& input, unsigned int& pos, const unsigned int size)
{
    string temp = "";
    while( pos < size && (isNumber(input[pos]) || input[pos]=='.'))
    {
        temp += input[pos];
        pos++;
    }
    pos--;
    if(temp!="")
        return new Constant(strtod(temp.c_str(),0));
    return 0; // en caso que no entro al bucle
}
Operation* Lexer::outOper(const string& input, unsigned int& pos, const unsigned int size)
{
    string temp = input.substr(pos,1);
    if( pos < size && isOper(temp))//mientras tenga el numero correcto de operadores(siempre hay 1 numero mas que los operadores)
        return new Operation(temp);
    return 0;
}

Operation* Lexer::outParen(const string& input, unsigned int& pos, const unsigned int size, unsigned int& countPar)
{
    if( pos < size &&  input[pos] == '(')//mientras tenga el numero correcto de operadores(siempre hay 1 numero mas que los operadores)
    {
        countPar++;
        return new Operation("(");
    }
    return 0;
}

bool Lexer::searchCloseParen(stack<Operation*>& sOper, stack<Node*>& sOperand, unsigned int& countParen)
{
    while(!sOperand.empty() && (!sOper.empty() && sOper.top()->getSymbol() != "("))//En caso no encuentre el parentesis de abertura y en caso que la pila de operadores no este vacio
    {
        sOper.top()->setRight(sOperand.top());
        sOperand.pop();//elimino el sacado
        sOper.top()->setLeft(sOperand.top());
        sOperand.pop();//elimino el sacado
        sOperand.push(sOper.top());
        sOper.pop();//elimino la operacion usada
    }
    if(!sOper.empty() && sOper.top()->getSymbol() == "(" )//elimino el parentesis que abria
    {
        sOper.pop();//elimino ese parentesis de abertura
        countParen--;
    }
    else//de no encontrar significa no hay quien cierre  el parentesis (error!)
    {
        cout<<"Error!..Falta parentesis de cierre"<<endl;
        return false;
    }
    return true;
}

Operation* Lexer::outFun(const string& input, const string& fun, unsigned int& pos)
{
    if(!isOper(fun))//evalua si es una funcion
        return 0;
    int pos2 = input.substr(pos).find(")");
    string operInter = input.substr(pos,pos2-1);
    //out.analyze();
    //return new Operation(fun,out.getResp(),out.getResp());
}

Operation* Lexer::outFun(const string& input, unsigned int& pos, const unsigned int size)
{
    string output = "";
    while(isLetterMin(input[pos]))
    {
        output += input[pos];
        pos++;
    }
    if(!isOper(output))//evalua si es una funcion
        return 0;
}

Node* Lexer::outCell(const string& input, unsigned int& pos, const unsigned int size)
{
    string colum = "",
           row   = "";
    while(isLetter(input[pos]))
    {
        colum += input[pos];
        pos++;
    }
    if(isNumber(input[pos]))
    {
        while(isNumber(input[pos]))
        {
            row += input[pos];
            pos++;
        }
        pos--;
        Cell *ptrCell = posCell(row,colum);
        ptrCell->addDependece(m_cellAct);
        return ptrCell;//sacara la direccion de memoria
    }else if(input[pos] == '(')
        return outFun(input,colum,++pos);
    return 0;
}

bool Lexer::analyze()
{
    char valueAct;
    unsigned countPar = 0;
    stack <Node*> sOperand;
    stack <Operation*> sOper;
    for(unsigned int i=0; i< m_sizeInput;i++)
    {
         valueAct = m_input[i];
        if(isNumber(valueAct) || valueAct == '.')//si es un numero o un punto decimal
            sOperand.push(outNumber(m_input,i,m_sizeInput));//no es necesario evaluar si devuelve nulo ya q con el if se dentota q devolvera un operando
        else if(isLetterMay(valueAct))
            sOperand.push(outCell(m_input,i,m_sizeInput));
        else if(isOper(m_input.substr(i,1)))//mientras tenga el numero correcto de operadores(siempre hay 1 numero mas que los operadores)
            Oper_Stack(outOper(m_input,i,m_sizeInput),sOper,sOperand);//inserta a la pila de operaciones el nuevo operador encapsulado y en caso sede ver prioridades las opera
        else if(isParent(valueAct))
            if(valueAct == '(')
                sOper.push(outParen(m_input,i,m_sizeInput,countPar));//inserta a la pila de operaciones el nuevo operador encapsulado y en caso sede ver prioridades las opera
            else if(m_input[i] == ')')//es  importante poner esto para a posterior condicion
                searchCloseParen(sOper,sOperand,countPar);
            else
            {
                cout<<"Error...ubicacion erronea del parentesis"<<endl;
                return false;
            }

    }
    if(countPar>0)//significa que hay algun parentesis que no se cerro
    {
        cout<<"Error! Falta cerrar un parentesis"<<endl;
        return false;
    }
    Oper_Stack(sOper,sOperand);//para terminar de vaciar la pila
    resp = sOperand.top();//en caso no este vacia la pila
}

/**
 * @brief Lexer::posCell obtendra la direccion de memoria de Cell en la posicion indicada
 * @param posR es un string de numeros que indica la fila en la matriz
 * @param posC es un string de letras que indica la columna en la matriz
 * @return la direccion de memoria de Cell en caso de no existir la crea con valor cero
 */
Cell* Lexer::posCell(string& posR, string& posC)
{
    int row   = strtod(posR.c_str(),0), //transforma row a un numero con strtod debido a que posR es un string de numeros
        colum = LetterToInt(posC,posC.size());
    nodeS<Cell>* nodo = m_matiz->find_node(colum,row);
    if(nodo)
    {
        return nodo->get_dato();
    }
    Cell *cell = new Cell(0,m_matiz);
    m_matiz->insert_node(*cell,colum,row);
    return m_matiz->find_node(colum,row)->get_dato();
}

bool Lexer::Oper_Stack(Operation* op, stack<Operation*>& sOper, stack<Node*>& sOperand)
{
    if(!sOper.empty())//en caso que la pila de operadores no este vacio
        if(sOperand.size()>1 && *op < *(sOper.top()))//en caso op es menor entonces el top de la pila lo opera
        {
            sOper.top()->setRight(sOperand.top());//asigno como Node derecho al tope de la pila de sOperand
            sOperand.pop();//elimino el sacado
            sOper.top()->setLeft(sOperand.top());//asigno como Node izquierdo al actual tope de la pila de sOpreand
            sOperand.pop();//elimino el sacado
            sOperand.push(sOper.top());//una vez ya dado los valres necesarios a la Operation lo inserto a la pila de sOperand
            sOper.pop();//elimino la operacion usada
        }
    sOper.push(op);//agrego el nuevo operador a la pila
    return true;
}

bool Lexer::Oper_Stack(stack<Operation*>& sOper, stack<Node*>& sOperand)
{
    while(!sOperand.empty() && !sOper.empty())//en caso que la pila de operadores no este vacio
    {
        sOper.top()->setRight(sOperand.top());
        sOperand.pop();//elimino el sacado
        sOper.top()->setLeft(sOperand.top());
        sOperand.pop();//elimino el sacado
        sOperand.push(sOper.top());
        sOper.pop();//elimino la operacion usada
    }
    return true;
}
Lexer::~Lexer()
{
    //dtor
}
