// Copyright 2023 Yashina Anastasia

#include "include/area_calculation.h"
#include <string>
#include <utility>
#include <cmath>

Polygon::Polygon() { point_count = 0; }

void Polygon::addPoint(std::pair <double, double> new_point) {
    for (int i = 0; i < point_count; i++)
        if (points[i] == new_point)
            throw std::string("This point already exists");
    points.push_back(new_point);
    point_count++;
}

double Polygon::countArea() {
    if (point_count < 3)
        throw std::string("Add more points");
    double final_s = 0, sum1 = 0, sum2 = 0;
    points.push_back(points[0]);
    for (int i = 0; i < point_count; i++) {
        sum1 += points[i].first * points[i + 1].second;
        sum2 += points[i].second * points[i + 1].first;
    }
    points.pop_back();
    final_s = fabs(sum1 - sum2) / 2;
    return final_s;
}

void Polygon::deletePoint(std::pair <double, double> deleting_point) {
    bool f = 0;
    for (int i = 0; i < point_count; i++)
        if (points[i] == deleting_point) {
            points.erase(points.begin() + i);
            point_count--;
            f = 1;
            break;
        }
    if (f == 0)
        throw std::string("This point doesn't exist");
}


