#include "Lexer.h"
list<string> Lexer::m_listOp(5);
Lexer::Lexer(Matrix<Cell> *matrix,const string& input):m_matrix(matrix),m_input(input){}

void Lexer::initOper()
{
    m_listOp.push_back("+");
    m_listOp.push_back("-");
    m_listOp.push_back("*");
    m_listOp.push_back("/");
    m_listOp.push_back("^");
}
bool Lexer::isOper(string val)
{
    if(val=="")
        return false;
    for(list<string>::iterator it=m_listOp.begin(); it != m_listOp.end();it++)
        if((*it) == val)
        {
            return true;
        }

    return false;
}
void Lexer::analyze(listOperations &m_output)
{
    string temp = "";
    Cell* cell = 0;
    int operaciones =-1;
    int operandos = 0;
    bool hizo =false;
    //int countP = 0, countOp = 0;
    for(unsigned int i=0; i< m_input.size();i++)
    {
        hizo=0;
        cout<<"operandos: "<<operandos<<"  operaciones: "<<operaciones<<endl;
        temp = "";
        if(isNumber(m_input[i]))cout<<"oparecions...."<<endl;
        if((isNumber(m_input[i]) || m_input[i]=='.') && (operandos-1 == operaciones))
        {
            cout<<"---->"<<m_input.substr(i,1)<<endl;
            while(isNumber(m_input[i]) || m_input[i]=='.')
            {
                temp += m_input[i];
                i++;
            }
            cout<<"lexer-> analyse "<<temp<<endl;
            m_output.push_back(new Token(strtod(temp.c_str(),0)));//ingreso un token como numero
            operandos++;
            //hizo =1;
            temp = "";
        }
        cout<<"---->"<<m_input.substr(i,1)<<endl;
        if(isOper(m_input.substr(i,1)) && (operandos-2 == operaciones))
        {
            cout<<"Lexer opp "<<m_input[i]<<endl;
            m_output.push_back(new Token(0,0,m_input.substr(i,1)));
            operaciones++;
            hizo = true;
            continue;
        }
        if(isLetterMay(m_input[i]) && (operandos-1 == operaciones))
        {
            cout<<"letra may"<<endl;
            while(isLetterMay(m_input[i]))
            {
                temp += m_input[i];
                i++;
            }
            if(isNumber(m_input[i]))
            {
                cout<<"busca filas"<<endl;
                while(isNumber(m_input[i]))
                {
                    temp += m_input[i];
                    i++;
                }
                cell = posCell(temp);
                if(cell)
                {
                    cout<<"tiene celda"<<endl;
                    m_output.push_back(new Token(0,cell));
                    operandos++;
                    temp = "";
                }
                //sacra la direccion de memoria
            }else if(isLetter(m_input[i]))//evalua el string para sacar un nombre y luego ver si es una funcion
            {
                while(isLetter(m_input[i]))
                {
                    temp += m_input[i];
                    i++;
                }
                if(isOper(temp))//evalua si es una funcion
                {
                    cout<<"Lexer celda "<<temp<<endl;
                    m_output.push_back(new Token(0,0,temp));
                    operandos++;
                }else break;//de no ser operacion hay un error con el string
            }
            temp = "";
        }
        else if(isLetter(m_input[i]))//evalua el string para sacar un nombre y luego ver si es una funcion
        {
            while(isLetter(m_input[i]))
                {
                    temp += m_input[i];
                    i++;
                }
                if(isOper(temp))//evalua si es una funcion
                {
                    cout<<"Lexer funcion "<<temp<<endl;
                    m_output.push_back(new Token(0,0,temp));
                    operandos++;
                }else break;;//de no ser operacion hay un error con el string
        }
        else if(isParent(m_input[i]))
        {

        }
        else if((m_input[i]!=' ' &&!hizo) || operaciones > operandos-2)
        {
            cout<<operandos<<" "<<operaciones<<endl;
            cout<<m_input[i]<<"cc"<<endl;
            cout<<"se sale"<<endl;
            m_output.clear();
            break;
        }
    }
    cout<<"operandos: "<<operandos<<"  operaciones: "<<operaciones<<endl;
    if(operaciones != operandos-2)
        m_output.clear();

}
Cell* Lexer::posCell(string posM)
{
    int row = 0,colum = 0;
    string temp="";
    int sizePos = posM.size();
    for(unsigned int i=sizePos-1; i>=0;i--)
    {
        if(isNumber(posM[i]))
        {
            while(isNumber(posM[i]))
            {
                temp = posM[i]+temp;
                i--;
            }
            row = strtod(temp.c_str(),0);
        }else return 0;
        if(isLetterMay(posM[i]))
        {
            int auxUb = i;
            while(isLetterMay(posM[i]))
            {
                colum += (((int)(posM[i])-64)*(pow(25,auxUb-i)));//ubicacion de columna deacuerdo al abecedario
                i--;
            }
            return m_matrix->searchCell(row,colum);
        }else return 0;
    }

    return 0;
}
Lexer::~Lexer()
{
    //dtor
}
