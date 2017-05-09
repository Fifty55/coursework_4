#ifndef TASK_4_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>



#define TASK_4_H_INCLUDED
 //-------------------------------------------------------------------------------------
template <typename axis_X, typename axis_Y>
class vertex

{

    public:

    vertex(int _No, axis_X _x, axis_Y _y){

    No=_No;

    x =_x;

    y =_y;

    }

    vertex(std::istream&fin);

    vertex(const vertex &_vertex);

    ~vertex();



    int get_vertex_numebr();

    axis_X get_x();

    axis_Y get_y();

    private:

    int No;

    axis_X x;

    axis_Y y;

};
//-----------------------------------------------------------------------------//


vertex::vertex(std::istream & fin)

{
    fin>>No>>x>>y;

}

vertex::vertex(const vertex &_vertex)

{
    No=_vertex.No;

    x =_vertex.x;

    y =_vertex.y;
}

vertex::~vertex(){}

//-----------------------------------------------------------------------------//

inline int vertex::get_vertex_numebr()
{
    return (No);
}

inline float vertex::get_x()
{
    return (x);
}

inline float vertex::get_y()
{
    return (y);
}


//-------------------------------------------------------------------------------//
class triangle

{
    public:

        triangle(int triangle_number,vertex first, vertex second, vertex third, std::vector<int> *neighbor);

        triangle(int triangle_number, int vertexa_number,int vertexb_number, int vertexc_number, std::vector<int> *neighbor);

        triangle(const triangle &_triangle);

        triangle(std::istream & fin);

        ~triangle();


        int get_triangle_number();

        int get_first_vertex();

        int get_second_vertex();

        int get_third_vertex();

        int get_number_of_neighbor();

        // calculate centre

        // calculate r

    private:

        int vertexa, vertexb, vertexc, triangle_No;

        std::vector<int> neighbor_point;

};
//------------------------------------------------------------------------------------------------------------------------//
    triangle::triangle(int _triangle_No,vertex first, vertex second, vertex third, std::vector<int> *neighbor)   // constructor
    {
        triangle_No=_triangle_No;

        vertexa=first.get_vertex_numebr();

        vertexb=second.get_vertex_numebr();

        vertexc=third.get_vertex_numebr();

        neighbor_point=*neighbor;
    }

    triangle::triangle(int _triangle_No, int vertexa_number, int vertexb_number, int vertexc_number, std::vector<int> *neighbor) // constructor

    {
        triangle_No=_triangle_No;

        vertexa=vertexa_number;

        vertexb=vertexb_number;

        vertexc=vertexc_number;

        neighbor_point=*neighbor;
    }

    triangle::triangle(const triangle &_triangle)

    {
        triangle_No=_triangle.triangle_No;

        vertexa=_triangle.vertexa;

        vertexb=_triangle.vertexb;

        vertexc=_triangle.vertexc;

        neighbor_point=_triangle.neighbor_point;

    }

    triangle::triangle(std::istream &fin)

    {

        fin >> triangle_No >> vertexa >> vertexb >> vertexc;

    }

    triangle::~triangle()

    {



    }

//-----------------------------------------------------------------------------------------//

inline int triangle::get_triangle_number()

{
    return (triangle_No);
}

inline int triangle::get_first_vertex()

{
     return (vertexa);
}

inline int triangle::get_second_vertex()

{
     return (vertexb);
}

inline int triangle::get_third_vertex()

{
    return (vertexc);
}

inline int triangle::get_number_of_neighbor()

{
    return(neighbor_point.size());
}
//-----------------------------------------------------------------------------------------//
class ramp_functioner

    {

    public:

        ramp_functioner(const int _c):c(_c){}     //constructor

        ~ramp_functioner();

        ramp_functioner(const ramp_functioner &_ramp_functioner);

        ramp_functioner(std::istream & fin);

        float operator() (float x, float y);

    private:

        int c;     // can not use constant because of copy constrcutor


    };

    ramp_functioner::~ramp_functioner(){};

    ramp_functioner::ramp_functioner (const ramp_functioner &_ramp_functioner)

        {

            c = _ramp_functioner.c;

        };

    ramp_functioner::ramp_functioner(std::istream & fin)

        {

            fin>>c;

        };

    inline float ramp_functioner::operator()(float x, float y)

        {
            return (c*x+y);

        }

#endif // TASK_4_H_INCLUDED
