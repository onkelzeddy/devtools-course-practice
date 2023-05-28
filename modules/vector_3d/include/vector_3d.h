// Copyright 2023 Goncharova Anna

#ifndef MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_H_
#define MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_H_

#include <vector>
#include <stdexcept>
#include <cmath>

class Vector3d {
 public:
    Vector3d();
    Vector3d(double x, double y, double z);
    double& operator[](double a);
    const double& operator[](double a) const;
    double get_norma();
    Vector3d get_normalization();
    static double scalar_mult(const Vector3d& vec1, const Vector3d& vec2);
    static Vector3d vector_mult(const Vector3d& vec1, const Vector3d& vec2);
 private:
    std::vector<double> data;
};

#endif  // MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_H_
