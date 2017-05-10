#ifndef VERTEX_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define VERTEX_H_INCLUDED
template <typename T>
class vertex

{

    public:

    typedef T data_type;

    vertex(int _No=0, T _x=0, T _y=0):No(_No), x(_x), y(_y){}

    vertex(const vertex<T> &_vertex);

    ~vertex();

    vertex(std::istream&fin);



    friend std::ostream& operator<<(std::ostream& out, vertex<T>&_vertex)
    {

    out<< _vertex.No <<"  "<<_vertex.x<<"  "<<_vertex.y<<"\n";

    return out;

    }

    vertex<T> operator = (const vertex<T> &_vertex)
    {

        No=_vertex.No;

        x =_vertex.x;

        y =_vertex.y;

    }

    int get_vertex_numebr();

    T get_x();

    T get_y();


    private:

    int No;

    T x;

    T y;

};

//------------------------------------------------------------------//

template <typename T>
vertex<T>::vertex(const vertex<T> &_vertex)
{
    No=_vertex.No;

    x =_vertex.x;

    y =_vertex.y;
}

template <typename T>
vertex<T>::~vertex(){}

template <typename T>
vertex<T>::vertex(std::istream & fin)

{
    fin>>No>>x>>y;

}


//------------------------------------------------------------------//

template <typename T>
inline int vertex<T>::get_vertex_numebr()
{
    return (No);
}

template <typename T>
inline T vertex<T>::get_x()
{
    return (x);
}

template <typename T>
inline T vertex<T>::get_y()
{
    return (y);
}

#endif // VERTEX_H_INCLUDED
