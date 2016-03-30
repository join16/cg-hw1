//
// Created by Join on 2016. 3. 25..
//
#include <iostream>
#include "math.h"

#include "vector.h"

// constructors

Vector::Vector() : x(0), y(0), z(0) {}

Vector::Vector(double _x, double _y, double _z)
  : x(_x), y(_y), z(_z) {}

// invalid vector constructor
Vector::Vector(bool _valid) : Vector() {
  valid = _valid;
}

// copy constructor
Vector::Vector(const Vector &v) {
  x = v.x;
  y = v.y;
  z = v.z;
}


// static methods

double Vector::dotProduct(Vector v1, Vector v2) {
  return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector Vector::crossProduct(Vector v1, Vector v2) {
  double resultX = (v1.y * v2.z) - (v2.y * v1.z);
  double resultY = (v1.z * v2.x) - (v2.z * v1.x);
  double resultZ = (v1.x * v2.y) - (v2.x * v1.y);

  return Vector(resultX, resultY, resultZ);
}

Vector Vector::operator+(Vector v) {
  return Vector(x + v.x, y + v.y, z + v.z);
}
Vector Vector::operator-(Vector v) {
  return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator*(double num) {
  return Vector(x * num, y * num, z * num);
}

void Vector::print() {
  if (valid) {
    printf("Vector (%f, %f, %f)\n", x, y, z);
  } else {
    printf("Invalid Vector!\n");
  };
};

void Vector::normalize() {
  double size = getSize();

  x /= size;
  y /= size;
  z /= size;
}

double Vector::getSize() {
  return sqrt((x * x) + (y * y) + (z * z));
}

double Vector::getX() {
  return x;
}

double Vector::getY() {
  return y;
}

double Vector::getZ() {
  return z;
}

bool Vector::isValid() {
  return valid;
}