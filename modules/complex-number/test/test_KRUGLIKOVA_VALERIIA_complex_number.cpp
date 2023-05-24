// Copyright 2023 Kruglikova Valeriia
#include <gtest/gtest.h>
#include "include/complex_number.h"
TEST(Kruglikova_Valeriia_ComplexNumberTest, zero_multipication) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(5., 3.);

    // Assert
    EXPECT_EQ(z1, z1 * z2);
}

TEST(Kruglikova_Valeriia_ComplexNumberTest, one_multipication) {
    // Arrange
    double re = 1.0;
    double im = 0.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(5., 3.);

    // Assert
    EXPECT_EQ(z2, z1 * z2);
}

TEST(Kruglikova_Valeriia_ComplexNumberTest, getter_setter) {
    // Arrange
    double re = 1.0;
    double im = 0.0;

    // Act
    ComplexNumber z1;
    z1.setIm(im);
    z1.setRe(re);
    // Assert
    EXPECT_EQ(z1.getRe(), re);
    EXPECT_EQ(z1.getIm(), im);
}
