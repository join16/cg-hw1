//
// Created by Join on 2016. 3. 30..
//

#include "src/lib/math/matrix44.h"
#include "src/lib/math/vector.h"
#include "src/lib/math/transformation.h"

int main() {

  Vector v1(1, 1, 1), v2(100, 5, 3), v3(500, 4, 1);

  Transformation trans;

  trans.setRotationByAxisVector(v1, v2, v3);

  trans.print();

  v1.print();
  v2.print();
  v3.print();

  return 0;
}