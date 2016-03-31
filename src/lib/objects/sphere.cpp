#include <iostream>
#include <math.h>

#include "sphere.h"

//
// constructors
//

Sphere::Sphere(double _radius) : radius(_radius) { }

Sphere::Sphere(double _radius, Vector _core) : radius(_radius) {
    core = Vector(_core);
}

//
// destructor
//

Sphere::~Sphere() {}

//
// methods
//

void Sphere::transform(Transformation trans) {
    core = trans.getTransformed(core);
}

Vector Sphere::getIntersection(Vector direction, Vector start) {

    // x,y,z of direction vector (dx, dy, dz)
    double dx(direction.getX()), dy(direction.getY()), dz(direction.getZ());

    // x,y,z of start vector (sx, sy, sz)
    double sx(start.getX()), sy(start.getY()), sz(start.getZ());

    // x,y,z of core of sphere (cx, cy, cz)
    double cx(core.getX()), cy(core.getY()), cz(core.getZ());

    // let intersection point (x,y,z) = (t * dx + sx, t * dy + sy, t * dz + sz),
    // sphere: (x-cx)^2 + (y-cy)^2 + (z-cz)^2 = (radius)^2

    // solve above equation
    // for equation At^2 + 2Bt + C = 0
    double A = direction.getSquareSum();
    double B = Vector::dotProduct(direction, start - core);
    double C = (start - core).getSquareSum() - (radius * radius);

    double discriminant = (B * B) - (A * C);

    // roots of equation
    double t1, t2;

    // if Discriminant < 0, return invalid vector
    if (discriminant < 0) {
        return Vector(false);
    }

    t1 = (-B - sqrt(discriminant)) / A;
    t2 = (-B + sqrt(discriminant)) / A;

    Vector v1((t1 * dx) + sx, (t1 * dy) + sy, (t1 * dz) + sz);
    Vector v2((t2 * dx) + sx, (t2 * dy) + sy, (t2 * dz) + sz);

    // if t < 0, intersection is being COP
    if (t1 < 0) {
        return (t2 < 0) ?
            Vector(false) :
            Vector(v2);

    } else {
        return (t1 < 0) ?
            Vector(false) :
            Vector(v1);
            
    }

    return (v1.getSize() >= v2.getSize()) ?
           Vector(v2) :
           Vector(v1);
}

void Sphere::print() {
    core.print();

    std::cout << radius << std::endl;
}