// Copyright 2023 Mitin Romans

#include <gtest/gtest.h>
#include <cmath>

#include "include/complex_number.h"

TEST(Mitin_Roman_ComplexNumberTest, assigment_test) {
    // Arrange
    ComplexNumber num(123, 13);
    ComplexNumber z1(2, 0);

    // Act
    z1 = num;

    // Assert
    EXPECT_EQ(z1.getRe(), 123);
    EXPECT_EQ(z1.getIm(), 13);
}

TEST(Mitin_Roman_ComplexNumberTest, 4root_of_minus_1) {
    // Arrange
    double re = 1 / std::sqrt(2);
    double im = 1 / std::sqrt(2);
    ComplexNumber num(re, im);

    // Act
    ComplexNumber z1 = num * num;
    ComplexNumber z2 = z1 * z1;

    // Assert
    EXPECT_DOUBLE_EQ(z1.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(z1.getIm(), 1.0);

    EXPECT_DOUBLE_EQ(z2.getRe(), -1.0);
    EXPECT_DOUBLE_EQ(z2.getIm(), 0.0);
}

TEST(Mitin_Roman_ComplexNumberTest, divide_1_by_i) {
    // Arrange
    ComplexNumber num(1.0, 0.0);
    ComplexNumber i(0.0, 1.0);

    // Act
    ComplexNumber z1 = num / i;
    ComplexNumber z2 = z1 / i;
    ComplexNumber z3 = z2 / i;

    // Assert
    EXPECT_DOUBLE_EQ(z1.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(z1.getIm(), -1.0);

    EXPECT_DOUBLE_EQ(z2.getRe(), -1.0);
    EXPECT_DOUBLE_EQ(z2.getIm(), 0.0);

    EXPECT_DOUBLE_EQ(z3.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(z3.getIm(), 1.0);
}
