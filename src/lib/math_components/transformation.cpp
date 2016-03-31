#include <iostream>
#include <math.h>

#include "transformation.h"

//
// constructors
//

Transformation::Transformation() {
    
    matrix = new Matrix44;

    // set matrix as I
    matrix->toIdentityMatrix();
}

Transformation::Transformation(Matrix44 _matrix) {
    matrix = new Matrix44(_matrix);
}

Transformation::Transformation(const Transformation &trans) {
    matrix = new Matrix44(trans.getMatrix());
}

//
// static methods
//

Transformation Transformation::composite(Transformation trans1, Transformation trans2) {
    Matrix44 _matrix = Matrix44::multiply(trans1.getMatrix(), trans2.getMatrix());

    return Transformation(_matrix);
}

//
// methods
//

void Transformation::setRotationByAxisVector(Vector x, Vector y, Vector z) {

    matrix->toIdentityMatrix();

    x.normalize();
    y.normalize();
    z.normalize();

    matrix->setValue(0, 0, x.getX());
    matrix->setValue(0, 1, x.getY());
    matrix->setValue(0, 2, x.getZ());

    matrix->setValue(1, 0, y.getX());
    matrix->setValue(1, 1, y.getY());
    matrix->setValue(1, 2, y.getZ());

    matrix->setValue(2, 0, z.getX());
    matrix->setValue(2, 1, z.getY());
    matrix->setValue(2, 2, z.getZ());
}

void Transformation::setRotationByAngle(int axis, double angle) {

    matrix->toIdentityMatrix();

    double radian = (angle * M_PI) / 180;

    switch (axis) {

        case ROTATION_X_AXIS:
            matrix->setValue(0, 0, 1);
            matrix->setValue(1, 1, cos(radian));
            matrix->setValue(1, 2, -sin(radian));
            matrix->setValue(2, 1, sin(radian));
            matrix->setValue(1, 2, cos(radian));
            break;

        case ROTATION_Y_AXIS:
            matrix->setValue(0, 0, cos(radian));
            matrix->setValue(0, 2, sin(radian));
            matrix->setValue(1, 1, 1);
            matrix->setValue(2, 0, -sin(radian));
            matrix->setValue(2, 2, cos(radian));
            break;

        case ROTATION_Z_AXIS:
            matrix->setValue(0, 0, cos(radian));
            matrix->setValue(0, 1, -sin(radian));
            matrix->setValue(1, 0, sin(radian));
            matrix->setValue(1, 1, cos(radian));
            matrix->setValue(2, 2, 1);
            break;

        default:
            throw "InvalidAxisException";

    }
}

void Transformation::setTranslation(double transX, double transY, double transZ) {

    matrix->toIdentityMatrix();

    matrix->setValue(0, 3, transX);
    matrix->setValue(1, 3, transY);
    matrix->setValue(2, 3, transZ);
}

void Transformation::setTranslation(double trans) {
    setTranslation(trans, trans, trans);
}

void Transformation::print() {
    std::cout << "Transformation:" << std::endl;
    matrix->print();
    std::cout << std::endl;
}

Matrix44 Transformation::getMatrix() const {
    return Matrix44(*matrix);
}

Vector Transformation::getTransformed(Vector v) {
    double arr[4] = {v.getX(), v.getY(), v.getZ(), 1};

    double transformedX = matrix->multiplyOneRow(0, arr);
    double transformedY = matrix->multiplyOneRow(1, arr);
    double transformedZ = matrix->multiplyOneRow(2, arr);

    return Vector(transformedX, transformedY, transformedZ);
}