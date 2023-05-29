// Copyright 2023 Yashina Anastasia

#include <gtest/gtest.h>
#include <utility>
#include "include/area_calculation.h"

TEST(PolygonArea, can_create_polygon) {
    ASSERT_NO_THROW(Polygon test);
}


TEST(PolygonArea, can_add_point) {
    Polygon test;
    double x = 5.4, y = 0.5;
    std::pair <double, double> point(x, y);
    ASSERT_NO_THROW(test.addPoint(point));
}

TEST(PolygonArea, cant_add_existing_point) {
    Polygon test;
    double x = 0.1, y = 8.6;
    std::pair <double, double> point(x, y);
    test.addPoint(point);
    ASSERT_ANY_THROW(test.addPoint(point));
}

TEST(PolygonArea, can_delete_point) {
    Polygon test;
    double x = 4.0, y = 7.8;
    std::pair <double, double> point(x, y);
    test.addPoint(point);
    ASSERT_NO_THROW(test.deletePoint(point));
}

TEST(PolygonArea, correct_count_4_points_area) {
    Polygon test;
    double x1 = 0.1, y1 = 1.5, x2 = 2.5, y2 = 5.0, area;
    std::pair <double, double> point1(x1, y1);
    std::pair <double, double> point2(x2, y1);
    std::pair <double, double> point3(x2, y2);
    std::pair <double, double> point4(x1, y2);
    test.addPoint(point1);
    test.addPoint(point2);
    test.addPoint(point3);
    test.addPoint(point4);
    area = test.countArea();
    EXPECT_DOUBLE_EQ((x2 - x1)*(y2 - y1), area);
}

TEST(PolygonArea, correct_count_3_points_area) {
    Polygon test;
    double x1 = 0.0, y1 = 0.0, x2 = 3.0, y2 = 5.5, area;
    std::pair <double, double> point1(x1, y1);
    std::pair <double, double> point2(x2, y1);
    std::pair <double, double> point3(x1, y2);
    test.addPoint(point1);
    test.addPoint(point2);
    test.addPoint(point3);
    area = test.countArea();
    EXPECT_DOUBLE_EQ((x2 - x1) * (y2 - y1)/2, area);
}
TEST(PolygonArea, cant_delete_not_existing_point) {
    Polygon test;
    double x1 = 1.5, x2 = 1.4, y = 2.5;
    std::pair <double, double> point(x1, y);
    test.addPoint(point);
    point = std::make_pair(x2, y);
    ASSERT_ANY_THROW(test.deletePoint(point));
}

TEST(PolygonArea, cant_count_area_less_then_3_points) {
    Polygon test;
    double x = 1.5, y = 2.5;
    std::pair <double, double> point(x, y);
    test.addPoint(point);
    ASSERT_ANY_THROW(test.countArea());
}

TEST(PolygonArea, point_count_is_changing) {
    Polygon test;
    double x = 1.5, y1 = 2.5, y2 = 3.5;
    std::pair <double, double> point1(x, y1);
    std::pair <double, double> point2(x, y2);
    test.addPoint(point1);
    test.addPoint(point2);
    test.deletePoint(point1);
    EXPECT_EQ(1, test.point_count);
}

