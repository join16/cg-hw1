
#ifndef CG_HW1_VECTOR_H
#define CG_HW1_VECTOR_H

class Vector {

public:

    // constructors
    Vector();
    Vector(double _x, double _y, double _z);
    Vector(bool _valid);
    Vector(const Vector &v);

    // static methods
    static Vector crossProduct(Vector v1, Vector v2);
    static double dotProduct(Vector v1, Vector v2);

    Vector operator+(Vector v);
    Vector operator-(Vector v);
    Vector operator*(double num);

    double getSquareSum();
    double getSize();
    double getX();
    double getY();
    double getZ();
    void print();
    bool isValid();
    void normalize();

private:
    double x, y, z;
    bool valid = true;
};


#endif //CG_HW1_VECTOR_H