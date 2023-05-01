// Copyright 2023 Bykova Aleksandra

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Bykova_Aleksandra_ComplexNumberTest, Can_Get_Re) {
    // Arrange
    double re = 5.0;
    double im = 1.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
}

TEST(Bykova_Aleksandra_ComplexNumberTest, Can_Get_Im) {
    // Arrange
    double re = 2.0;
    double im = 3.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Bykova_Aleksandra_ComplexNumberTest, Can_Set_Re) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;
    double re2 = -5.0;

    // Act
    ComplexNumber z(re1, im1);

    z.setRe(re2);

    // Assert
    EXPECT_DOUBLE_EQ(re2, z.getRe());
}

TEST(Bykova_Aleksandra_ComplexNumberTest, Can_Set_Im) {
    // Arrange
    double re1 = 1.0;
    double im1 = 6.0;
    double im2 = 4.0;

    // Act
    ComplexNumber z(re1, im1);

    z.setIm(im2);

    // Assert
    EXPECT_DOUBLE_EQ(im2, z.getIm());
}

TEST(Bykova_Aleksandra_ComplexNumberTest, Can_Add_Complex_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = 3.0;
    double re2 = 4.0;
    double im2 = -5.0;
    double re3 = 5.0;
    double im3 = -2.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 + z2, z3);
}

TEST(Bykova_Aleksandra_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    // Arrange
    double re1 = -3.0;
    double im1 = 6.0;
    double re2 = 2.0;
    double im2 = 7.0;
    double re3 = -5.0;
    double im3 = -1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 - z2, z3);
}


