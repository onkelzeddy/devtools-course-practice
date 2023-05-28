// Copyright 2023 Goncharova Anna

#include "include/vector_3d.h"

Vector3d::Vector3d(): data{ 0.0, 0.0, 0.0 } {}

Vector3d::Vector3d(double x, double y, double z): data { x, y, z } {}

double& Vector3d::operator[](double a) {
    if (a < 0 || a > 2)
        throw std::out_of_range("Index out of bounds!");
    return data[a];
}

const double& Vector3d::operator[](double a) const {
    if (a < 0 || a > 2)
        throw std::out_of_range("Index out of bounds!");
    return data[a];
}

double Vector3d::get_norma() {
    return std::sqrt(scalar_mult(*this, *this));
}

Vector3d Vector3d::get_normalization() {
    double norma = this->get_norma();
    if (!norma) {
        throw std::domain_error("No normalization!");
    }

    Vector3d ans(data[0] / norma, data[1] / norma, data[2] / norma);
    return ans;
}

double Vector3d::scalar_mult(const Vector3d& vec1, const Vector3d& vec2) {
    return (vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2]);
}

Vector3d Vector3d::vector_mult(const Vector3d& vec1, const Vector3d& vec2) {
    Vector3d answer;
    answer[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    answer[1] = -(vec1[0] * vec2[2] - vec1[2] * vec2[0]);
    answer[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];

    return answer;
}
