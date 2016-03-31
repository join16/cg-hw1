
#ifndef CG_HW1_TRANSFORMATION_H
#define CG_HW1_TRANSFORMATION_H

#include "matrix44.h"
#include "vector.h"

const int ROTATION_X_AXIS = 0;
const int ROTATION_Y_AXIS = 1;
const int ROTATION_Z_AXIS = 2;

class Transformation {

public:

    // constructors
    Transformation();
    Transformation(Matrix44 _matrix);
    Transformation(const Transformation &trans);

    // static methods
    static Transformation composite(Transformation trans1, Transformation trans2);

    void setRotationByAngle(int axis, double angle);
    void setRotationByAxisVector(Vector x, Vector y, Vector z);
    void setTranslation(double transX, double transY, double transZ);
    void setTranslation(double trans);
    Vector getTransformed(Vector v);
    void print();
    Matrix44 getMatrix() const;

private:
    Matrix44 *matrix;

};


#endif //CG_HW1_TRANSFORMATION_H
