// Copyright 2023 Korobeynikova Alice

#include "include/triangle.h"

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    : p1{p1}, p2{p2}, p3{p3} {}

std::array<Point, 3> Triangle::GetPoints() const {
    return {p1, p2, p3};
}

bool Triangle::Consist(const Point& p) const {
  double x[4] = {p.x, p1.x, p2.x, p3.x};
  double y[4] = {p.y, p1.y, p2.y, p3.y};
  auto a = (x[1] - x[0]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[1] - y[0]);
  auto b = (x[2] - x[0]) * (y[3] - y[2]) - (x[3] - x[2]) * (y[2] - y[0]);
  auto c = (x[3] - x[0]) * (y[1] - y[3]) - (x[1] - x[3]) * (y[3] - y[0]);

  return (a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0);
}
