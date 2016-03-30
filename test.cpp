//
// Created by Join on 2016. 3. 30..
//

#include "src/lib/math/matrix44.h"
#include "src/lib/math/vector.h"

int main() {

  Matrix44 m1, m2;

  m1.setValue(0, 0, 2);
  m1.setValue(1, 1, 2);
  m1.setValue(2, 2, 2);
  m1.setValue(3, 3, 1);

  m2.setValue(0, 0, 2);
  m2.setValue(1, 1, 2);
  m2.setValue(2, 2, 2);
  m2.setValue(3, 3, 1);

  Vector v1(1, 1, 1), v2(100, 5, 3);

  Vector v3 = Vector::crossProduct(v2, v1);

  v3.print();

  Matrix44 m3 = Matrix44::multiply(m1, m2);

  m3.print();

  return 0;
}