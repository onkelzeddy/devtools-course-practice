// Copyright 2023 Tychinin Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tychinin_Alexey_ComplexNumberTest, Test_Getters) {
  constexpr double re = 1., im = 2.;
  ComplexNumber first(re, im);

  ASSERT_EQ(first.getRe(), re);
  ASSERT_EQ(first.getIm(), im);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_SetRe) {
  constexpr double re = 1.;
  ComplexNumber first{};
  first.setRe(re);

  ASSERT_EQ(first.getRe(), re);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_SetIm) {
  constexpr double im = 2.;
  ComplexNumber first{};
  first.setIm(im);

  ASSERT_EQ(first.getIm(), im);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_Eq) {
  ComplexNumber first{};
  ComplexNumber second{};

  ASSERT_EQ(first, second);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_NEq) {
  ComplexNumber first{};
  ComplexNumber second{14., 144.};

  ASSERT_NE(first, second);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_Assign) {
  ComplexNumber first{2., 5.};
  ComplexNumber second = first;

  ASSERT_EQ(first, second);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_Add) {
  ComplexNumber first(12., 11.0);
  ComplexNumber second(9., 3.);
  ComplexNumber expected(first.getRe() + second.getRe(),
                         first.getIm() + second.getIm());

  ASSERT_EQ(first + second, expected);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_Sub) {
  ComplexNumber first(12., 11.0);
  ComplexNumber second(9., 3.);
  ComplexNumber expected(first.getRe() - second.getRe(),
                         first.getIm() - second.getIm());

  ASSERT_EQ(first - second, expected);
}

TEST(Tychinin_Alexey_ComplexNumberTest, Test_Divide_By_Zero) {
  ComplexNumber first(15., 25.);

  ASSERT_THROW(first / ComplexNumber{}, std::string);
}
