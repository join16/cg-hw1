//
// Created by Join on 2016. 3. 30..
//

#include <iostream>

#include "src/lib/math_components/matrix44.h"
#include "src/lib/math_components/vector.h"
#include "src/lib/math_components/transformation.h"

using namespace std;

int main() {

    Matrix44 m1(2);

    Matrix44 m(m1);

    cout << "In Main" << endl;

    cout << "Debugg" << endl;

    m1.print();

    return 0;
}