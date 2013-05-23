#ifndef MATRIX_H
#define MATRIX_H
#include <map>


typedef int coor;
using namespace std;
template<typename T>
class Matrix
{
    public:
        Matrix(int =20,int =20);
        bool insertValue(coor, coor,T);
        bool inRange(coor, coor);
        bool cellEmpty(coor, coor);
        T* searchCell(coor, coor);
        virtual ~Matrix();
    protected:
        map<coor,map<coor,T> > m_matrix;
        coor m_sizeRow;
        coor m_sizeColum;
    private:


};
template<typename T>
Matrix<T>::Matrix(coor r, coor c):m_sizeRow(r),m_sizeColum(c){}
template<typename T>
bool Matrix<T>::insertValue(coor r, coor c, T newValue)
{
    if(inRange(r,c))
        m_matrix[r][c] = newValue;
    return false;
}
template<typename T>
bool Matrix<T>::inRange(coor r, coor c)
{
    return (r>=1 && r<=m_sizeRow) && (c>=1 && c<=m_sizeColum);
}
template<typename T>
T* Matrix<T>::searchCell(coor r, coor c)
{
    if(!cellEmpty(r,c))
        return &m_matrix[r][c];
    return 0;
}
template<typename T>
bool Matrix<T>::cellEmpty(coor r, coor c)
{
    if(inRange(r,c))
        if(m_matrix.count(r)>0)
            return m_matrix[r].count(c)==0;
    return true;
}
template<typename T>
Matrix<T>::~Matrix()
{
    //dtor
}


#endif // MATRIX_H
