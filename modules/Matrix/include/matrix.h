// Copyright 2023 Kruglikova Valeriia

#ifndef  MODULES_MATRIX_INCLUDE_MATRIX_H_
#define  MODULES_MATRIX_INCLUDE_MATRIX_H_
#include <iostream>

class matrix {
    double** Matrix;
    int rows;
    int columns;

 public:
    matrix();
    matrix(int rows, int columns);
    matrix(double** Matrix, int rows, int columns);
    matrix(const matrix& Matrix);
    ~matrix();
    matrix operator+(const matrix& Matrix);
    matrix operator-(const matrix& Matrix);
    matrix operator*(const matrix& Matrix);
    matrix operator*(double d);
    matrix transpose();
    matrix reverse();
    matrix& operator=(const matrix& MaStrix);
    double determinant();
    double trace();
    int getRows();
    int getColumns();
    double** getMatrix();
    friend double det(double** Matrix, int size);
    friend matrix InvMatr(matrix Matrix);
    friend double* iter(matrix Matrix, double* y);
};
#endif  //  MODULES_MATRIX_INCLUDE_MATRIX_H_
