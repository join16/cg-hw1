
#ifndef CG_HW1_TRIANGLE_H
#define CG_HW1_TRIANGLE_H

#include "object.h"
#include "../math_components/transformation.h"
#include "../math_components/plane.h"

class Triangle : public Object {

public:
    Triangle(Vector _vertexA, Vector _vertexB, Vector _vertexC);

    virtual void transform(Transformation trnas);
    virtual Vector getIntersection(Vector direction, Vector start);
    virtual void print();

private:
    Vector vertexA;
    Vector vertexB;
    Vector vertexC;

    Plane *plane;

    bool isOnSameSide(Vector p1, Vector p2, Vector edgeEnd1, Vector edgeEnd2);
    bool isInTriangle(Vector v);
};


#endif //CG_HW1_TRIANGLE_H
