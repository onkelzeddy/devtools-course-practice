// Copyright 2023 Kruglikova Valeriia


#include "include/matrix.h"
#include <math.h>
#include <iostream>


matrix::matrix() {
    columns = 0;
    rows = 0;
    Matrix = nullptr;
}
matrix::matrix(int rows, int columns) {
    this->columns = columns;
    this->rows = rows;
    this->Matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        this->Matrix[i] = new double[columns] {};
}
matrix::matrix(double** Matrix, int rows, int columns) {
    this->columns = columns;
    this->rows = rows;
    this->Matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        this->Matrix[i] = new double[columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            this->Matrix[i][j] = Matrix[i][j];
}
matrix::matrix(const matrix& Matrix) {
    this->columns = Matrix.columns;
    this->rows = Matrix.rows;
    this->Matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        this->Matrix[i] = new double[columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            this->Matrix[i][j] = Matrix.Matrix[i][j];
}
matrix::~matrix() {
    for (int i = 0; i < rows; i++)
       delete[] Matrix[i];
    delete[] Matrix;
}
matrix matrix::operator+(const matrix& Matrix) {
    matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.Matrix[i][j] = this->Matrix[i][j] + Matrix.Matrix[i][j];
    return (result);
}
matrix matrix::operator-(const matrix& Matrix) {
    matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.Matrix[i][j] = this->Matrix[i][j] - Matrix.Matrix[i][j];
    return result;
}
matrix matrix::operator*(const matrix& Matrix) {
    matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < Matrix.columns; j++)
            for (int k = 0; k < this->columns; k++)
                result.Matrix[i][j] += this->Matrix[i][k] * Matrix.Matrix[k][j];
    return result;
}
matrix matrix::operator*(double d) {
    matrix Matrix(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            Matrix.Matrix[i][j] = this->Matrix[i][j] * d;
    return (Matrix);
}
matrix& matrix::operator=(const matrix& Matrix) {
    this->columns = Matrix.columns;
    this->rows = Matrix.rows;
    this->Matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        this->Matrix[i] = new double[columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            this->Matrix[i][j] = Matrix.Matrix[i][j];
    return *this;
}
double det(double** Matrix, int size) {
    if (size == 1) {
        return Matrix[0][0];
    } else if (size == 2) {
        return Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0];
    } else {
        double result = 0;
        for (int k = 0; k < size; k++) {
            double** matrix = new double* [size - 1];
            for (int i = 0; i < size - 1; i++) {
                matrix[i] = new double[size - 1];
            }
            for (int i = 1; i < size; i++) {
                int t = 0;
                for (int j = 0; j < size; j++) {
                    if (j == k)
                        continue;
                    matrix[i - 1][t] = Matrix[i][j];
                    t++;
                }
            }
            result += pow(-1, k + 2) * Matrix[0][k] * det(matrix, size - 1);
        }
        return result;
    }
}
double matrix::determinant() {
    return det(Matrix, columns);
}
matrix matrix::transpose() {
    matrix result(columns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result.Matrix[j][i] = Matrix[i][j];
        }
    }
    return result;
}
matrix matrix::reverse() {
    return InvMatr(*this);
}
int matrix::getRows() {
    return rows;
}
int matrix::getColumns() {
    return columns;
}
double** matrix::getMatrix() {
    return Matrix;
}
double* iter(matrix Matrix, double* y) {
    double* res = new double[Matrix.rows];
    for (int i = 0; i < Matrix.rows; i++)
        res[i] = y[i] / Matrix.Matrix[i][i];
    double eps = 0.0001;
    double* Xn = new double[Matrix.rows];
    do {
        for (int i = 0; i < Matrix.rows; i++) {
            Xn[i] = y[i] / Matrix.Matrix[i][i];
            for (int j = 0; j < Matrix.rows; j++) {
                if (i == j)
                    continue;
                else
                    Xn[i] -= Matrix.Matrix[i][j] / Matrix.Matrix[i][i] * res[j];
            }
        }
        bool flag = true;
        for (int i = 0; i < Matrix.rows - 1; i++)
            if (abs(Xn[i] - res[i]) > eps) {
                flag = false;
                break;
            }
        for (int i = 0; i < Matrix.rows; i++)
            res[i] = Xn[i];
        if (flag)
            break;
    } while (true);
    return res;
}
matrix InvMatr(matrix Matrix) {
    matrix result(Matrix.rows, Matrix.columns);
    double* y = new double[Matrix.rows];
    double* itr;
    for (int i = 0; i < Matrix.rows; i++) {
        for (int j = 0; j < Matrix.rows; j++) {
            if (i == j)
                y[j] = 1;
            else
                y[j] = 0;
        }
        itr = iter(Matrix, y);
        for (int k = 0; k < Matrix.rows; k++)
            result.Matrix[k][i] = itr[k];
    }
    return result;
}
double matrix::trace() {
    double result = 0;
    for (int i = 0; i < this->rows; i++)
        result += this->Matrix[i][i];
    return result;
}
