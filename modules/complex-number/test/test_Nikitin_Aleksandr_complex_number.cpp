// Copyright 2023 Nikitin Aleksandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Nikitin_Aleksandr_ComplexNumberTest, Test_Get) {
  // Arrange
  ComplexNumber x(1.2, 2.1);

  // Act
  double re = x.getRe();
  double im = x.getIm();

  // Assert
  ASSERT_EQ(re, 1.2);
  ASSERT_EQ(im, 2.1);
}

TEST(Nikitin_Aleksandr_ComplexNumberTest, Test_Set) {
  // Arrange
  ComplexNumber x(2.0, 10.0);

  // Act
  x.setRe(3.4);
  x.setIm(5.6);

  // Assert
  ASSERT_EQ(x.getRe(), 3.4);
  ASSERT_EQ(x.getIm(), 5.6);
}

TEST(Nikitin_Aleksandr_ComplexNumberTest, Test_Difference) {
  // Arrange
  ComplexNumber x(7.8, 10.0);
  ComplexNumber y(4.5, 6.7);

  // Act
  ComplexNumber result = x - y;

  // Assert
  ASSERT_EQ(result.getRe(), 3.3);
  ASSERT_EQ(result.getIm(), 3.3);
}
