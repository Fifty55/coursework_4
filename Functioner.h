#ifndef FUNCTIONER_H_INCLUDED
#include "Triangle.h"

#define FUNCTIONER_H_INCLUDED
class ramp_functioner

    {

    public:

        ramp_functioner(const int _c):c(_c){}     //constructor

        ~ramp_functioner();

        ramp_functioner(const ramp_functioner &_ramp_functioner);

        ramp_functioner(std::istream & fin);

        float operator() (float x, float y);

        double integration_method1(triangle *_triangle)

        {
            return ( (c * (_triangle->get_circumcentre().get_x() )+_triangle->get_circumcentre().get_y() ) * _triangle->get_area ());
        }

        template <typename container>
        typename container::data_type integration_method2( container *a,container *b,container *d,triangle *_triangle)
        {
           return (  _triangle->get_area()* (c*(a->get_x()+b->get_x()+d
                                                ->get_x() )+a->get_y()+b->get_y()+d->get_y() )*1/3 );
        }


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

    template<typename container>
    inline container calculate_area( vertex<container> *vertexa, vertex<container> *vertexb, vertex<container> *vertexc)

    {
       return( std::abs( (vertexa->get_x() * (vertexb->get_y() - vertexc->get_y()) + vertexb->get_x() * (vertexc->get_y() - vertexa->get_y()) + vertexc->get_x() * (vertexa->get_y() - vertexb->get_y() ) ) *0.5 ) );
    }
#endif // FUNCTIONER_H_INCLUDED
