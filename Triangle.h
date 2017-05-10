#ifndef TRIANGLE_H_INCLUDED

#include "vertex.h"

#define TRIANGLE_H_INCLUDED


class triangle

{
    public:

        template<typename T>
        triangle(int triangle_number,
                                    T first,
                                        T second,
                                            T third,
                                                double _area,
                                                    vertex <double> _circle_centre);

        triangle(int triangle_number, int vertexa_number,int vertexb_number, int vertexc_number, double _area, vertex <double> _circle_centre);

        triangle(const triangle &_triangle);

        triangle(std::istream & fin);

        ~triangle();


        int get_triangle_number();

        int get_first_vertex();

        int get_second_vertex();

        int get_third_vertex();

        double get_area ();

        vertex<double> get_circumcentre();

        void updata_area(double _area);

        void updata_circumcentre(vertex<double> *_centre);

        template<typename container>
        container line_function (vertex<container> *p1,
                                                     vertex<container> *p2,
                                                     vertex<container> *p3); //This

        template<typename container>
        bool PointInTriangle (vertex<container> *pt,
                              vertex<container> *v1,
                              vertex<container> *v2,
                              vertex<container> *v3);


        template<typename container>
        void calculate_centre (vertex<container> *p1, vertex<container> *p2, vertex<container> *p3);

        bool check_Delaunay( std::map <int, std::vector <int> > &_triangle_map, std::vector <vertex <double>* > &_node, std::vector <triangle*> &_triangle_data)

        {

                double R = sqrt( pow( (circle_centre.get_x() - _node[vertexa]->get_x() ), 2) + pow( (circle_centre.get_y() - _node[vertexa]->get_y() ),2) );

                unsigned int number_of_vertex=  _triangle_map[triangle_No].size();

                bool result=1;

                std::vector <int> perpare_to_check;

                //std::cout<<_triangle_map[vertexa][1]<<"\n"<<triangle_No;


                for(int i=0;i<_triangle_map[vertexa].size();i++)

                {
                     //std::cout<< _triangle_map[vertexa][i]<<"a \n";

                     //std::cout<< _triangle_data[ _triangle_map[vertexa][i] ]->get_second_vertex()<<"b \n";

                     //std::cout<<vertexa<<" "<<vertexb<<" "<<vertexc<<" \n";
                    if(_triangle_map[vertexa][i]!=triangle_No)
                        {


                            if (_triangle_data[ _triangle_map[vertexa][i] ]->get_first_vertex() !=vertexa &&
                                _triangle_data[ _triangle_map[vertexa][i] ]->get_first_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexa][i] ]->get_first_vertex() !=vertexc)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexa][i] ]->get_first_vertex() );

                            if (_triangle_data[ _triangle_map[vertexa][i] ]->get_second_vertex() !=vertexa &&
                                _triangle_data[ _triangle_map[vertexa][i] ]->get_second_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexa][i] ]->get_second_vertex() !=vertexc)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexa][i] ]->get_second_vertex() );

                            if (_triangle_data[ _triangle_map[vertexa][i] ]->get_third_vertex() !=vertexa &&
                                _triangle_data[ _triangle_map[vertexa][i] ]->get_third_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexa][i] ]->get_third_vertex() !=vertexc)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexa][i] ]->get_third_vertex() );

                        }
                }

                for(int i=0;i<_triangle_map[vertexb].size();i++)

                {
                    if(_triangle_map[vertexb][i]!=triangle_No)
                        {


                            if (_triangle_data[ _triangle_map[vertexb][i] ]->get_first_vertex() !=vertexa &&
                                _triangle_data[ _triangle_map[vertexb][i] ]->get_first_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexb][i] ]->get_first_vertex() !=vertexc)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexb][i] ]->get_first_vertex() );

                            if (_triangle_data[ _triangle_map[vertexb][i] ]->get_second_vertex() !=vertexa &&
                                _triangle_data[ _triangle_map[vertexb][i] ]->get_second_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexb][i] ]->get_second_vertex() !=vertexc)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexb][i] ]->get_second_vertex() );

                            if (_triangle_data[ _triangle_map[vertexb][i] ]->get_third_vertex() !=vertexa &&
                                _triangle_data[ _triangle_map[vertexb][i] ]->get_third_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexb][i] ]->get_third_vertex() !=vertexc)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexb][i] ]->get_third_vertex() );

                        }
                }

                for(int i=0;i<_triangle_map[vertexc].size();i++)

                {
                    if(_triangle_map[vertexc][i]!=triangle_No)
                        {


                            if (_triangle_data[ _triangle_map[vertexc][i] ]->get_first_vertex() !=vertexc &&
                                _triangle_data[ _triangle_map[vertexc][i] ]->get_first_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexc][i] ]->get_first_vertex() !=vertexa)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexc][i] ]->get_first_vertex() );

                            if (_triangle_data[ _triangle_map[vertexc][i] ]->get_second_vertex() !=vertexc &&
                                _triangle_data[ _triangle_map[vertexc][i] ]->get_second_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexc][i] ]->get_second_vertex() !=vertexa)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexc][i] ]->get_second_vertex() );

                            if (_triangle_data[ _triangle_map[vertexc][i] ]->get_third_vertex() !=vertexc &&
                                _triangle_data[ _triangle_map[vertexc][i] ]->get_third_vertex() !=vertexb &&
                                _triangle_data[ _triangle_map[vertexc][i] ]->get_third_vertex() !=vertexa)

                            perpare_to_check.push_back(_triangle_data[ _triangle_map[vertexc][i] ]->get_third_vertex() );

                        }
                }

                std::sort(perpare_to_check.begin(), perpare_to_check.end());

                std::vector<int>::iterator it;



                it = std::unique (perpare_to_check.begin(), perpare_to_check.end());
                                                         //                ^
                perpare_to_check.resize( std::distance(perpare_to_check.begin(),it) );


                for(int i=0;i<perpare_to_check.size();i++)

                {

                    if(sqrt( pow( (circle_centre.get_x() - _node[ perpare_to_check[i] ]->get_x() ), 2) +
                             pow( (circle_centre.get_y() - _node[ perpare_to_check[i] ]->get_y() ),2) ) < R)
                             {
                                  result =0;
                             }

                }


                perpare_to_check.clear();


                    return (result);




    //*_triangle_data[_triangle_number]->get_first_vertex;

        }


        // calculate r

    private:

        int vertexa, vertexb, vertexc, triangle_No;

        double area;

        vertex <double> circle_centre;

};
//------------------------------------------------------------------------------------------------------------------------//
    template<typename T>
    triangle ::triangle(int _triangle_No,T first,
                                        T second,
                                        T third,
                                        double _area,
                                        vertex <double> _circle_centre)   // constructor
    {
        triangle_No=_triangle_No;

        vertexa=first.get_vertex_numebr();

        vertexb=second.get_vertex_numebr();

        vertexc=third.get_vertex_numebr();

        area = _area;

        circle_centre= _circle_centre;


    }


    triangle::triangle(int _triangle_No, int vertexa_number, int vertexb_number, int vertexc_number, double _area, vertex <double> _circle_centre) // constructor

    {
        triangle_No=_triangle_No;

        vertexa=vertexa_number;

        vertexb=vertexb_number;

        vertexc=vertexc_number;

        area = _area;

        circle_centre= _circle_centre;

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

inline double triangle::get_area()

{
    return (area);
}
inline void triangle::updata_area(double _area)

{
    area=_area;
}

template<typename container>  //????????//
container triangle::line_function (vertex<container> *p1,
                                    vertex<container> *p2,
                                     vertex<container> *p3)

{
    return (p1->get_x() - p3->get_x()) * (p2->get_y() - p3->get_y() ) - (p2->get_x() - p3->get_x() )*(p1->get_y() - p3->get_y() );
}

template<typename container>
bool triangle::PointInTriangle (vertex<container> *pt,
                               vertex<container> *v1,
                               vertex<container> *v2,
                                vertex<container> *v3)
{
bool b1, b2, b3;

    b1 = line_function(pt, v1, v2) < 0.0f;
    b2 = line_function(pt, v2, v3) < 0.0f;
    b3 = line_function(pt, v3, v1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

template<typename container>
void triangle::calculate_centre (vertex<container> *p1, vertex<container> *p2, vertex<container> *p3)
{
    double Ox,Oy,D;

    D=2*(p1->get_x() * (p2->get_y() - p3->get_y())+ p2->get_x() *(p3->get_y() - p1->get_y()) + p3->get_x() *(p1->get_y() - p2->get_y()));

    Ox= ( (pow(p1->get_x(),2) + pow(p1->get_y(),2) )*(p2->get_y()-p3->get_y()) + (pow(p2->get_x(),2) + pow(p2->get_y(),2) ) * (p3->get_y()-p1->get_y()) +(pow(p3->get_x(),2) + pow(p3->get_y(),2) )* (p1->get_y()-p2->get_y()) )/D;

    Oy= ( (pow(p1->get_x(),2) + pow(p1->get_y(),2) )*(p3->get_x() - p2->get_x()) + (pow(p2->get_x(),2) + pow(p2->get_y(),2) ) * (p1->get_x()-p3->get_x()) +(pow(p3->get_x(),2) + pow(p3->get_y(),2) )* (p2->get_x()-p1->get_x()) )/D;

    circle_centre = vertex<double>(-1,Ox,Oy);
}

inline vertex<double> triangle::get_circumcentre()
{
    return(circle_centre);
}

inline void triangle::updata_circumcentre(vertex<double> *_centre)
{
    circle_centre = *_centre;

}
#endif // TRIANGLE_H_INCLUDED
