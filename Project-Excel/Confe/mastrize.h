#ifndef MASTRIZE_H
#define MASTRIZE_H
#include "nodes.h"

using namespace std;


/**
 *brief matrizE esta clase sera nuestro contenedor de nodos;
 */
template<typename T>
class matrizE
{

public:
    typedef nodeS<T> NODES;  //para factorizar codigo
    typedef NODES* NODESP;
    typedef unordered_map<coord,NODESP> CONTEINER; // para factorizar codigo
    /**
     * @brief matrizE constructor por defecto
     */
    matrizE(){
        CONTEINER a;
        m_row=a;
        m_col=a;
    }
    /**
     * @brief insert_node inserta nodo mediante sus ejes X y Y
     * @param T elemento que contendra el valor del nodo
     * @param axisx cooordenada X del nodo a insertar
     * @param axisy coordenada Y del nodo a insertar
     */
     void insert_node(const T dato,const coord axisx,const coord axisy);
    /**
     * @brief find_node busca un nodo en los contenedores
     * @param axisx busca mediante su eje X
     * @param axisy busca mediante su eje Y
     * @return retorna el puntero al nodo buscado
     */
    NODESP find_node(const coord axisx,const coord axisy);
    /**
     * @brief link_nodes enlaza los nodos
     */
    void link_nodes();
    /**
     * @brief change_row cambia de coordena a los nodos de la fila
     * @param new_coord nueva coordenada a cambiar
     */
    void change_row(const coord old_coord,const coord new_coord);
    /**
     * @brief change_col cambia coordenada a los nodos de la columna
     * @param new_coord nueva coordenada a cambiar
     */
    void change_col(const coord old_coord,const coord new_coord);
    /**
     * @brief change_only_one cambia de poscision a un nodo
     * @param old_X su antigua coordenada X
     * @param old_Y su antigua coordenada Y
     * @param new_X su nueva coordenada X
     * @param new_Y su nueva coordenada Y
     */
    void change_only_one(const coord old_X,const coord old_Y,const coord new_X,const coord new_Y);
    /**
     * @brief delete_node elimina un nodo de los contenedores
     */
    void delete_node(const coord axis_X,const coord axis_Y);
    /**
     * @brief get_cadenaX
     * @param y
     * @return
     */
    NODESP get_cadenaX(const coord y){return m_col[y];}
    /**
     * @brief get_cadenaY
     * @param x
     * @return
     */
    NODESP get_cadenaY(const coord x){return m_row[x];}

    CONTEINER get_conte(){return m_col;}
private:
    /**
     * @brief m_row  contenedor de columnas, sera usado para insertar en filas
     */
    CONTEINER m_row;
    /**
     * @brief m_col contenedor de filas, sera usado para insertar en columnas
     */
    CONTEINER m_col;
    /**
     * @brief insert_X esta funcion inserta el nodo mediante el eje X mediante un Y fijo
     * @param root el nodo raiz del contenedor
     * @param node_new el nuevo nodo que sera ingresado
     */
    void insert_X(NODESP &root,NODESP node_new);
    /**
     * @brief insert_Y esta funcion inserta el nodo mediante el eje Y mediante un X fijo
     * @param root el nodo raiz del contenedor
     * @param node_new el nuevo nodo que sera ingresado
     */
    void insert_Y(NODESP &root,NODESP node_new);
    /**
     * @brief find_X esta funcion buscara un nodo mediante una coordenada
     * @param root este nodo es la raiz en la cual se buscara al nodo
     * @param axisx este es la coordenada a la cual se buscara
     * @return retorna el nodo encontrado y si no lo encuentra lo bota como NULL
     */
    NODES* find_X(NODESP root,const coord axisx);
    /**
     * @brief find_Y esta funcion buscara un nodo mediante una coordenada
     * @param root este nodo es la raiz en la cual se buscara al nodo
     * @param axisy este es la coordenada a la cual se buscara
     * @return retorna el nodo encontrado y si no lo encuentra lo bota como NULL
     */
    NODES* find_Y(NODESP root,const coord axisy);
    /**
     * @brief delete_X
     * @param root
     * @param X
     */
    void delete_X(NODESP &root, const coord X);
    /**
     * @brief delete_Y
     * @param root
     * @param Y
     */
    void delete_Y(NODESP &root, const coord Y);

};


//examinar este codigo al ingresar 2 nodos iguales
template<typename T>
void matrizE<T>::insert_node(const T dato,const coord axisx,const coord axisy)
{
    auto gotR = m_row.find(axisy); // busco
    cout<<1<<endl;
    auto gotC = m_col.find(axisx);
    cout<<2<<endl;
    if( gotR == m_row.end() && gotC == m_col.end())
    {
        cout<<3<<endl;
        NODESP nodenew = new NODES(dato,axisx,axisy);
        m_row.insert({axisx,nodenew});
        m_col.insert({axisy,nodenew});
    }
    else
    {
        cout<<4<<endl;
        if(gotC == m_col.end())
        {
            cout<<5<<endl;
            NODESP nodenew = new NODES(dato,axisx,axisy);
            m_col.insert({axisx,nodenew});
            insert_X(m_row[axisy],nodenew);
        }
        else {
            cout<<6<<endl;
            if(gotR == m_row.end())
            {
                cout<<7<<endl;
                NODESP nodenew = new NODES(dato,axisx,axisy);
                m_row.insert({axisy,nodenew});
                insert_Y(m_col[axisx],nodenew);
            }
            else
            {
                cout<<8<<endl;
                NODESP nodenew = new NODES(dato,axisx,axisy);
                insert_X(m_row[axisy],nodenew);
                insert_Y(m_col[axisx],nodenew);
            }
        }
    }
}

template<typename T>
void matrizE<T>::insert_X(NODESP &root, NODESP node_new)
{
    if(root->m_coordx == node_new->m_coordx)
    {
        cout<<"es igual"<<endl;
        root->set_dato(*(node_new->get_dato()));
        cout<<"bn ahi loco"<<endl;
        return;
    }
    else if(!root || root->m_coordx > node_new->m_coordx )
        {
            node_new->m_ptr_right = root;
            root = node_new;
            cout<<"lo hizo X"<<endl;
            return;
        }
    if(!root)
        insert_Y(root->m_ptr_down,node_new);
    else
        return;
}


template<typename T>
void matrizE<T>::insert_Y(NODESP &root, NODESP node_new)
{
    if(root->m_coordy == node_new->m_coordy)
    {
        cout<<"es igual"<<endl;
        root->set_dato(*(node_new->get_dato()));
        cout<<"bn ahi loco"<<endl;
        return;
    }
    else if(!root || root->m_coordy > node_new->m_coordy)
        {
            node_new->m_ptr_down = root;
            root = node_new;
            cout<<"lo hizo Y"<<endl;
            return;
    }
            if(!root)
                insert_Y(root->m_ptr_down,node_new);
            else
                return;

}


template<typename T>
nodeS<T>* matrizE<T>::find_node(const coord axisx, const coord axisy)
{
    return find_X(m_col[axisy],axisx);
}

template<typename T>
nodeS<T>* matrizE<T>::find_X(NODESP root,const coord axisx)
{
    while(root)
    {
        if(root->m_coordx == axisx)
            return root;
        root=root->m_ptr_right;
    }
    return 0;
}

template<typename T>
nodeS<T>* matrizE<T>::find_Y(NODESP root,const coord axisy)
{
    while(root)
    {
        if(root->m_coordy == axisy)
            return root;
        root=root->m_ptr_down;
    }
    return 0;
}

template<typename T>
void matrizE<T>::link_nodes()
{


}

template<typename T>
void matrizE<T>::change_row(const coord old_coord,const coord new_coord)
{
    auto n1 = m_col[old_coord];
    m_col.insert({new_coord,n1});
    m_col.erase(old_coord);
}

template<typename T>
void matrizE<T>::change_col(const coord old_coord,const coord new_coord)
{
    auto n2 = m_row[old_coord];
    m_row.insert({new_coord,n2});
    m_row.erase(old_coord);
}

template<typename T>
void matrizE<T>::change_only_one(const coord old_X, const coord old_Y, const coord new_X, const coord new_Y)
{

}
template<typename T>
void matrizE<T>::delete_node(const coord axis_X, const coord axis_Y)
{
    auto c1 =m_col.find(axis_X);
    auto r1 = m_row.find(axis_Y);

    if(c1 == m_col.end() && r1 == m_row.end())
    {
        cout<<"el nodo no existe"<<endl;
        return;
    }
    else
    {
        if( c1.second->m_ptr_right == 0 && r1.second->m_ptr_down == 0)
        {
            m_col.erase(c1);  m_row.erase(r1);
            cout<< "jajaja<"<<endl;
        }
    }


}

template<typename T>
void matrizE<T>::delete_X(NODESP &root, const coord X)
{
        if((root->m_coordx == X) || (root->m_coordx > X))
            {
                root = root->m_ptr_right->m_ptr_right;
                return;
            }
        root = root->m_ptr_right;
}

template<typename T>
void matrizE<T>::delete_Y(NODESP &root, const coord Y)
{
    /*
        if((root->m_coordy == Y) || (root->m_coordy > Y))
        {
            root = root->m_ptr_down->m_ptr_down;
            return;
        }
        delete_Y(root->m_ptr_down,coord Y);
        */
}

#endif // MASTRIZE_H

