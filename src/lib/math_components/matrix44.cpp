#include <iostream>

#include "matrix44.h"

//
// Constructors
//

Matrix44::Matrix44(double defaultValue)
    : size(matrixSize) {
    initializeValues();
    clearMatrixValues(defaultValue);
}

Matrix44::Matrix44(const Matrix44 &m) : size(matrixSize) {
    initializeValues();

    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
            values[i][j] = m.getValue(i, j);
        }
    }
}

//
// Destructor
//

Matrix44::~Matrix44() {

    for (int i = 0; i < size; i++) {
        delete[] values[i];
    }

    delete[] values;
}

//
// Static methods
//

Matrix44 Matrix44::multiply(Matrix44 m1, Matrix44 m2) {
    double *col;
    double value;

    Matrix44 result;

    for (unsigned int i = 0; i < matrixSize; i++) {
        for (unsigned int j = 0; j < matrixSize; j++) {
            col = m2.getCol(j);

            value = m1.multiplyOneRow(i, col);

            result.setValue(i, j, value);
        }
    }

    return Matrix44(result);
}

void Matrix44::setValue(unsigned int row, unsigned int col, double value) {
    values[row][col] = value;
}

double Matrix44::getValue(unsigned int row, unsigned int col) const {
    return values[row][col];
}

void Matrix44::print() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << values[i][j] << ' ';
        }

        std::cout << std::endl;
    }
}

double *Matrix44::getRow(int rowNum) {
    double *row;

    row = new double[size];

    for (int i = 0; i < size; i++) {
        row[i] = values[rowNum][i];
    }

    return row;
}

double *Matrix44::getCol(int colNum) {
    double *col;

    col = new double[size];

    for (int i = 0; i < size; i++) {
        col[i] = values[i][colNum];
    }

    return col;
}

unsigned int Matrix44::getSize() {
    return size;
}

double Matrix44::multiplyOneRow(unsigned int row, double arr[matrixSize]) {
    double result = 0;

    for (unsigned int i = 0; i < size; i++) {
        result += getValue(row, i) * arr[i];
    }

    return result;
}

void Matrix44::toIdentityMatrix() {
    clearMatrixValues(0);
    setValue(0, 0, 1);
    setValue(1, 1, 1);
    setValue(2, 2, 1);
    setValue(3, 3, 1);
}

//
// Private methods
//

void Matrix44::initializeValues() {
    values = new double *[size];

    for (int i = 0; i < size; i++) {
        values[i] = new double[size];
    }
}

void Matrix44::clearMatrixValues(double value) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            values[i][j] = value;
        }
    }
}