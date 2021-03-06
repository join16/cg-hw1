
#ifndef CG_HW1_MATRIX44_H
#define CG_HW1_MATRIX44_H

const unsigned int matrixSize = 4;

class Matrix44 {

public:

    // constructors

    Matrix44(double defaultValue = 0);
    Matrix44(const Matrix44 &m);

    // destructor
    ~Matrix44();

    // static methods

    static Matrix44 multiply(Matrix44 m1, Matrix44 m2);

    unsigned int getSize();
    void print() const;
    void setValue(unsigned int row, unsigned int col, double value);
    double getValue(unsigned int row, unsigned int col) const;
    double *getRow(int rowNum);
    double *getCol(int colNum);
    double multiplyOneRow(unsigned int row, double arr[matrixSize]);
    void toIdentityMatrix();

private:

    // member variables
    double **values;
    unsigned int size;

    void initializeValues();
    void clearMatrixValues(double value = 0);
};


#endif //CG_HW1_MATRIX44_H
