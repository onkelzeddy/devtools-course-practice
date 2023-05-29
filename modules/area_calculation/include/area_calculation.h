// Copyright 2023 Yashina Anastasia

#ifndef MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_H_
#define MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_H_

#include <vector>
#include <utility>

class Polygon {
 public:
    int point_count;
    std::vector<std::pair <double, double>> points;
    Polygon();
    void addPoint(std::pair <double, double> new_point);
    double countArea();
    void deletePoint(std::pair <double, double> deleting_point);
};

#endif  // MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_H_
