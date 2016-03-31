
#include <iostream>
#include "triangle.h"

Triangle::Triangle(Vector _vertexA, Vector _vertexB, Vector _vertexC)
    : vertexA(_vertexA), vertexB(_vertexB), vertexC(_vertexC) {

    plane = new Plane(vertexA, vertexB, vertexC);
}

void Triangle::transform(Transformation trans) {
    vertexA = trans.getTransformed(vertexA);
    vertexB = trans.getTransformed(vertexB);
    vertexC = trans.getTransformed(vertexC);

    delete plane;
    plane = new Plane(vertexA, vertexB, vertexC);
}

Vector Triangle::getIntersection(Vector direction, Vector start) {

    // x,y,z of direction vector (dx, dy, dz)
    double dx(direction.getX()), dy(direction.getY()), dz(direction.getZ());

    // x,y,z of start vector (sx, sy, sz)
    double sx(start.getX()), sy(start.getY()), sz(start.getZ());

    // let intersection point (t * dx + sx, t * dy + sy, t * dz + sz)

    // for plane equation Ax + By + Cz + D = 0,

    double A = plane->getA();
    double B = plane->getB();
    double C = plane->getC();
    double D = plane->getD();

    // for equation Et = F - D;

    double E = (A * dx) + (B * dy) + (C * dz);
    double F = -((A * sx) + (B * sy) + (C * sz));

    // no roots exist, return invalid vector
    if (E == 0) {
        return Vector(false);
    }

    // root of equation
    double t = (F - D) * (1 / E);

    // intersection vector
    Vector v(t * dx + sx, t * dy + sy, t * dz + sz);

    return isInTriangle(v) ?
           v :
           Vector(false);
}

//
// private methods
//

bool Triangle::isInTriangle(Vector v) {

    bool isOnSameSideWithVertexA = isOnSameSide(v, vertexB, vertexA, vertexC);
    bool isOnSameSideWithVertexB = isOnSameSide(v, vertexC, vertexA, vertexB);
    bool isOnSameSideWithVertexC = isOnSameSide(v, vertexA, vertexB, vertexC);

    return isOnSameSideWithVertexA &&
           isOnSameSideWithVertexB &&
           isOnSameSideWithVertexC;
}

bool Triangle::isOnSameSide(Vector p1, Vector p2, Vector edgeEnd1, Vector edgeEnd2) {

    Vector edge = (edgeEnd2 - edgeEnd1);

    Vector v1 = (p1 - edgeEnd1);
    Vector v2 = (p2 - edgeEnd1);

    // cross product of (one vertex of edge - point) and edge
    Vector cp1 = Vector::crossProduct(edge, v1);
    Vector cp2 = Vector::crossProduct(edge, v2);

    return Vector::dotProduct(cp1, cp2) >= 0;
}

void Triangle::print() {
    std::cout << "Printing Triangle:" << std::endl;
    vertexA.print();
    vertexB.print();
    vertexC.print();
    std::cout << std::endl;
}