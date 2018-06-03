#ifndef BEZIER_H
#define BEZIER_H

#include "object.h"

class Bezier: public Object
{
    public:
        virtual Intsct* Intersect(const Ray& rO, const Ray& rt);
};


#endif
