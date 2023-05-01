// Copyright 2023 Korobeynikova Alice

#pragma once
#include <array>

struct Point {
  double x, y;
};

class Triangle {
  Point p1, p2, p3;

 public:
  Triangle(const Point& p1, const Point& p2, const Point& p3);
  std::array<Point, 3> GetPoints() const;
  bool Consist(const Point& p) const;
};
