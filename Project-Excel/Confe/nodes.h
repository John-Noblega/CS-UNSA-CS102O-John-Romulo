#ifndef NODES_H
#define NODES_H
#include "resources.h"
#include <iostream>



template<typename T> class matrizE;
/**
  \brief esta clase es la estructura de la clase matriz
*/

template<typename T>
class nodeS
{
    friend  class matrizE<T>; // la clase nodo sera amiga de la clase matrizE
    typedef nodeS<T> NODES;
public:
    /**
     * @brief nodeS constructor por defecto 
     */
    nodeS():m_dato(0),m_coordx(0),m_coordy(0),m_ptr_down(0),m_ptr_right(0){}
    /**
     * @brief nodeS contructor por parametro que solo es necesario ingresar el tipo de dato
     * @param dato este elemento se implementara en m_dato
     * @param axis_x este elemento es la coordenada X en la que se posicionara dicho nodo
     * @param axis_y este elemento es la coordenada Y en la que se posicionara dicho nodo
     * @param ptr_down este elmento se implemetara en m_ptr_down
     * @param ptr_right este elemento se implementara en m_ptr_down
     */
    nodeS(const T dato,const coord axis_x,const coord axis_y,NODES *ptr_down=0,NODES *ptr_right=0)
        :m_dato(dato),m_coordx(axis_x),m_coordy(axis_y),m_ptr_down(ptr_down),m_ptr_right(ptr_right){}
    /**
     * @brief get_dato esta funcion retorda el dato por referencia
     * @return miembro m_dato del nodo
     */
    T* get_dato() {return &m_dato;}
    /**
     * @brief get_coordX esta funcion retorna la coordenada X de forma constante
     * @return miembro m_coordx del nodo
     */
    coord& get_coordX()const {return m_coordx;}
    /**
     * @brief get_coordY esta funcion retorna la coordenada X de forma constante
     * @return miembro m_coordy del nodo
     */
    coord& get_coordY()const {return m_coordy;}
    /**
     * @brief get_ptrRight esta funcion retorna el puntero al nodo de la derecha
     * @return miembro m_ptr_right del nodo
     */
    NODES* get_ptrRight(){return m_ptr_right;}
    /**
     * @brief get_ptrDown esta funcion retorna el puntero al nodo de abajo
     * @return miembro m_ptr_down del nodo
     */
    NODES* get_ptrDown(){return m_ptr_down;}
    /**
     * @brief set_dato sobreescribe el dato en el nodo dado
     * @param dato es el nuevo valor del dato
     */
    void set_dato(const T dato){m_dato =dato;}


private:
    /**
     * @brief m_dato este miebro es un dato template
     */
    T m_dato; 
    /**
     * @brief m_coordx miembro poscision X
     * @brief m_coordy miembro poscision Y
     */
    coord m_coordx,m_coordy;
    /**
     * @brief m_ptr_down este miembro es un puntero a un nodo hacia abajo
     */
    NODES *m_ptr_down;
    /**
     * @brief m_ptr_right este miembro es un puntero a un nodo hacia la derecha
     */
    NODES *m_ptr_right;
};

#endif // NODES_H
