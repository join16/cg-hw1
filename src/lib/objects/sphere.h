
#ifndef CG_HW1_SPHERE_H
#define CG_HW1_SPHERE_H

#include "object.h"
#include "../math_components/vector.h"

class Sphere : public Object {

public:
    Sphere(double _radius);
    Sphere(double _radius, Vector _core);

    ~Sphere();

    virtual void transform(Transformation trans);
    virtual Vector getIntersection(Vector direction, Vector start);
    virtual void print();

private:
    double radius;
    Vector core;

};


#endif //CG_HW1_SPHERE_H
