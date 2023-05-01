// Copyright 2023 ILYA UVARKIN

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Uvarkin_Ilya_ComplexNumberTest, SumImaginaryParts) {
  ComplexNumber num1(0, 40);
  ComplexNumber num2(0, 2);

  ComplexNumber rez = num1 + num2;

  ASSERT_EQ(rez.getRe(), 0);
  ASSERT_EQ(rez.getIm(), 42);
}

TEST(Uvarkin_Ilya_ComplexNumberTest, SumRealParts) {
  ComplexNumber num1(20, 0);
  ComplexNumber num2(5, 0);

  ComplexNumber rez = num1 + num2;

  ASSERT_EQ(rez.getRe(), 25);
  ASSERT_EQ(rez.getIm(), 0);
}

TEST(Uvarkin_Ilya_ComplexNumberTest, SumComplexNumber) {
  ComplexNumber num1(20, -5);
  ComplexNumber num2(-5, 10);

  ComplexNumber rez = num1 + num2;

  ASSERT_EQ(rez.getRe(), 15);
  ASSERT_EQ(rez.getIm(), 5);
}

TEST(Uvarkin_Ilya_ComplexNumberTest, MultipleComplexNumber) {
  ComplexNumber num1(5, 10);
  ComplexNumber num2(2, -5);

  ComplexNumber rez = num1 * num2;

  ASSERT_EQ(rez.getRe(), 60);
  ASSERT_EQ(rez.getIm(), -5);
}

TEST(Uvarkin_Ilya_ComplexNumberTest, DivideComplexNumberWithZero) {
  ComplexNumber num1(0, 0);
  ComplexNumber num2(0, 0);

  ASSERT_THROW((num1 / num2), std::string);
}

