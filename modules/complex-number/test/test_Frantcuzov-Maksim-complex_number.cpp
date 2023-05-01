// Copyright 2023 Frantcuzov Maksim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Frantcuzov_Maksim_ComplexNumberTest, Can_Multiple_Sum) {
    // Arrange
    ComplexNumber a(2.0, 3.0);
    ComplexNumber b(4.0, 5.0);
    ComplexNumber c(6.0, 7.0);
    ComplexNumber expect(12.0, 15.0);

    // Act
    ComplexNumber result = a + b + c;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Frantcuzov_Maksim_ComplexNumberTest, Test_Substruct) {
    // Arrange
    ComplexNumber a(13.6, 33.2);
    ComplexNumber b(13, 33);
    ComplexNumber expect(0.6, 0.2);

    // Act
    ComplexNumber result = a - b;

    // Assert
    ASSERT_NEAR(expect.getIm(), result.getIm(), 0.001);
    ASSERT_NEAR(expect.getRe(), result.getRe(), 0.001);
}

TEST(Frantcuzov_Maksim_ComplexNumberTest, Test_Negative_Mult) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(3.0, 4.0);
    ComplexNumber expect(-5.0, 10.0);

    // Act
    ComplexNumber result = a * b;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}
