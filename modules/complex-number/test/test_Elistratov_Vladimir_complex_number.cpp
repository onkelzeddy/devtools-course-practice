// Copyright 2023 Elistratov Vladimir

#include <gtest/gtest.h>

#include <tuple>

#include "include/complex_number.h"

TEST(Elistratov_V_complex_number, TEST_Substraction) {
  ComplexNumber z1(5.0, 5.0);
  ComplexNumber z2(2.0, 3.0);

  ComplexNumber expression = z1 - z2;

  EXPECT_EQ(expression, ComplexNumber(3.0, 2.0));
}

TEST(Elistratov_V_complex_number, TEST_Sum) {
  ComplexNumber z1(10.0, 0.0);
  ComplexNumber z2(0.0, 10.0);

  ComplexNumber expression = z1 + z2;

  EXPECT_EQ(expression, ComplexNumber(10.0, 10.0));
}

TEST(Elistratov_V_complex_number, TEST_Multiply) {
  ComplexNumber z1(5.0, 5.0);
  ComplexNumber z2(3.0, 3.0);

  ComplexNumber expression = z1 * z2;

  EXPECT_EQ(expression, ComplexNumber(0, 30));
}
