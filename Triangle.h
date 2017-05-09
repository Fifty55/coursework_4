#ifndef TRIANGLE_H_INCLUDED

#include "vertex.h"

#define TRIANGLE_H_INCLUDED


class triangle

{
    public:

        template<typename container>
        triangle(int triangle_number,
                                    vertex<typename container::data_type> first,
                                        vertex<typename container::data_type> second,
                                            vertex<typename container::data_type> third,
                                                double _area);

        triangle(int triangle_number, int vertexa_number,int vertexb_number, int vertexc_number, double _area);

        triangle(const triangle &_triangle);

        triangle(std::istream & fin);

        ~triangle();


        int get_triangle_number();

        int get_first_vertex();

        int get_second_vertex();

        int get_third_vertex();

        template<typename container, typename type>
        typename type::data_type line_function (container *p1,
                                                     container *p2,
                                                     container *p3); //This

        template<typename container>
        bool PointInTriangle (container *pt,
                              container *v1,
                              container *v2,
                              container *v3);



        // calculate centre

        // calculate r

    private:

        int vertexa, vertexb, vertexc, triangle_No;

        double area;

};
//------------------------------------------------------------------------------------------------------------------------//
    template<typename container>
    triangle::triangle(int _triangle_No,vertex<typename container::data_type> first,
                                                        vertex<typename container::data_type> second,
                                                            vertex<typename container::data_type> third,
                                                                double _area)   // constructor
    {
        triangle_No=_triangle_No;

        vertexa=first.get_vertex_numebr();

        vertexb=second.get_vertex_numebr();

        vertexc=third.get_vertex_numebr();


    }


    triangle::triangle(int _triangle_No, int vertexa_number, int vertexb_number, int vertexc_number, double _area) // constructor

    {
        triangle_No=_triangle_No;

        vertexa=vertexa_number;

        vertexb=vertexb_number;

        vertexc=vertexc_number;

    }


    triangle::triangle(const triangle &_triangle)

    {
        triangle_No=_triangle.triangle_No;

        vertexa=_triangle.vertexa;

        vertexb=_triangle.vertexb;

        vertexc=_triangle.vertexc;

    }


    triangle::triangle(std::istream &fin)

    {
        double nope;

        fin >> triangle_No >> vertexa >> vertexb >> vertexc;

        while ( fin.peek() != '\n')

        {
            fin>>nope;

            if (fin .eof()) break;
        }

    }


    triangle::~triangle()

    {}

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

template<typename container, typename type>  //????????//
typename type::data_type triangle::line_function (container *p1,
                                    container *p2,
                                     container *p3)

{
    return (p1->get_x() - p3->get_x()) * (p2->get_y() - p3->get_y() ) - (p2->get_x() - p3->get_x() )*(p1->get_y() - p3->get_y() );
}

template<typename container>
bool triangle::PointInTriangle (container *pt,
                               container *v1,
                               container *v2,
                                container *v3)
{
bool b1, b2, b3;

    b1 = line_function(pt, v1, v2) < 0.0f;
    b2 = line_function(pt, v2, v3) < 0.0f;
    b3 = line_function(pt, v3, v1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

#endif // TRIANGLE_H_INCLUDED
