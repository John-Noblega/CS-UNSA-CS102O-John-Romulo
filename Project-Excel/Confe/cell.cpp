#include "cell.h"

Cell::Cell()
{
    
}

tValue Cell::eval()
{
    //if(m_update)
        update();
    //cout<<m_value<<endl;
    return m_value;
}
Cell::~Cell()
{
    //dtor
}
