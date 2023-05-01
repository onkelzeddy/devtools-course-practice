// Copyright 2023 Korobeynikova Alice

#include <gtest/gtest.h>
#include <limits>
#include <cmath>

#include "include/triangle.h"

static bool approximatelyEqual(double x, double y) {
  return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

static bool operator==(const Point& p1, const Point& p2) {
  return approximatelyEqual(p1.x, p2.x) && approximatelyEqual(p1.y, p2.y);
}

TEST(Korobeynikova_TriangleConsistsPointTest, ParametrizedConstructor) {
  const Point p[3] = {Point{0, 0}, Point{0, 1}, Point{1, 0}};
  Triangle t(p[0], p[1], p[2]);
  auto points = t.GetPoints();
  for (size_t i = 0; i < 3; ++i) {
    ASSERT_EQ(points[i], p[i]);
  }
}

TEST(Korobeynikova_TriangleConsistsPointTest, TriangleConsistsPoint) {
  const Point p[3] = {{0, 0}, {0, 1}, {1, 0}};
  Triangle t(p[0], p[1], p[2]);
  Point p_inside_t{0.2, 0.2};
  ASSERT_TRUE(t.Consist(p_inside_t));
}

TEST(Korobeynikova_TriangleConsistsPointTest, TriangleDoesNotConsistPoint) {
  const Point p[3] = {{0, 0}, {0, 1}, {1, 0}};
  Triangle t(p[0], p[1], p[2]);
  Point p_not_inside_t{-0.5, 0.5};
  ASSERT_FALSE(t.Consist(p_not_inside_t));
}
