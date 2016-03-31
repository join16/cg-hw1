
#ifndef CG_HW1_PLANE_H
#define CG_HW1_PLANE_H

#include "vector.h"

class Plane {

public:
    Plane();
    Plane(Vector vertexA, Vector vertexB, Vector vertexC);

    void print();
    double getA();
    double getB();
    double getC();
    double getD();

private:

    // for Ax + By + Cz + D = 0, normal = (A, B, C)
    Vector normal;
    double A, B, C, D;
    Vector edgeAB, edgeBC, edgeCA;

};


#endif //CG_HW1_PLANE_H
