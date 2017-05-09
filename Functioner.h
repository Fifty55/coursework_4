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


#endif // FUNCTIONER_H_INCLUDED
