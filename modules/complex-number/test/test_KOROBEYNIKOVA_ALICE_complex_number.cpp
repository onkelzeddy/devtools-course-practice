// Copyright 2023 Alice Korobeynikova

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Korobeynikova_Alice_ComplexNumberTest, ParametrizedConstructor) {
  double real = -7.5, imaginary = 2;
  ComplexNumber number(real, imaginary);
  ASSERT_EQ(number.getRe(), real);
  ASSERT_EQ(number.getIm(), imaginary);
}

TEST(Korobeynikova_Alice_ComplexNumberTest, CopyConstructor) {
  double real = -7.5, imaginary = 2;
  ComplexNumber number(ComplexNumber(real, imaginary));
  ASSERT_EQ(number.getRe(), real);
  ASSERT_EQ(number.getIm(), imaginary);
}

TEST(Korobeynikova_Alice_ComplexNumberTest, ComparisonOperator) {
  double real = -7.5, imaginary = 2;
  ComplexNumber number1(real, imaginary), number2(-7.5, 2);
  ASSERT_EQ(number1, number2);
}

TEST(Korobeynikova_Alice_ComplexNumberTest, OperatorPlus) {
  double real = -7.5, imaginary = 2;
  ComplexNumber number1(real, imaginary), number2(-real, -imaginary);
  ASSERT_EQ(number1 + number2, ComplexNumber(0, 0));
}
