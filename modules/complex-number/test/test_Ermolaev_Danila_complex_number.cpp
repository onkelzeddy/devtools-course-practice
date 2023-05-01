// Copyright 2023 Ermolaev Danila

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ermolaev_Danila_ComplexNumberTest, New_number_equal_null) {
  ComplexNumber z;
  EXPECT_DOUBLE_EQ((z.getRe()), 0.0);
  EXPECT_DOUBLE_EQ((z.getIm()), 0.0);
}

TEST(Ermolaev_Danila_ComplexNumberTest, Can_set_only_im) {
  ComplexNumber z;
  double im = 5.0;

  z.setIm(im);

  EXPECT_EQ(im, z.getIm());
}

TEST(Ermolaev_Danila_ComplexNumberTest, Can_Sum_Complex_Numbers) {
  double re1 = 3.0;
  double im1 = 0.123;

  ComplexNumber z1(re1, im1);

  double re2 = 5.0;
  double im2 = 0.8;

  ComplexNumber z2(re2, im2);

  ComplexNumber sum = z1 + z2;

  EXPECT_EQ(8, sum.getRe());
  EXPECT_EQ(0.923, sum.getIm());
}

TEST(Ermolaev_Danila_ComplexNumberTest, Can_get_Re) {
  ComplexNumber number(42, 24);

  const double re = number.getRe();

  ASSERT_EQ(re, 42);
}

TEST(Ermolaev_Danila_ComplexNumberTest, Can_get_Im) {
  ComplexNumber number(42, 24);

  const double im = number.getIm();

  ASSERT_EQ(im, 24);
}
