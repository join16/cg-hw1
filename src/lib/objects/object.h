#ifndef CG_HW1_OBJECT_H
#define CG_HW1_OBJECT_H

// abstract class

#include "../math_components/vector.h"
#include "../math_components/transformation.h"

class Object {

public:

    virtual ~Object() = 0;

    virtual void transform(Transformation trans) = 0;
    virtual Vector getIntersection(Vector direction, Vector start) = 0;
    virtual void print() = 0;

};

#endif //CG_HW1_OBJECT_H