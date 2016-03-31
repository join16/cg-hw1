
#include <iostream>

#include "plane.h"

Plane::Plane() : Plane(Vector(), Vector(), Vector()) { }

Plane::Plane(Vector vertexA, Vector vertexB, Vector vertexC) {
    edgeAB = vertexB - vertexA;
    edgeBC = vertexC - vertexB;
    edgeCA = vertexC - vertexA;

    normal = Vector::crossProduct(edgeAB, edgeBC);

    A = normal.getX();
    B = normal.getY();
    C = normal.getZ();
    D = -Vector::dotProduct(normal, vertexA);
}

double Plane::getA() {
    return A;
}

double Plane::getB() {
    return B;
}

double Plane::getC() {
    return C;
}

double Plane::getD() {
    return D;
}

void Plane::print() {
    printf("Plane: %fx + %fy + %fz + %f = 0\n", A, B, C, D);
}