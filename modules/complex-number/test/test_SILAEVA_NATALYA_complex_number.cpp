// Copyright 2023 Natalya Silaeva

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Silaeva_Natalya_ComplexNumberTest, Can_Create_Complex_Number) {
    double re = 2.0;
    double im = 0.1;

    ComplexNumber res(re, im);

    EXPECT_EQ(re, res.getRe());
    EXPECT_EQ(im, res.getIm());
}

TEST(Silaeva_Natalya_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    double re1 = 0.3;
    double im1 = 0.1;

    double re2 = 0.8;
    double im2 = 0.6;

    ComplexNumber cnum1(0.3, 0.1);
    ComplexNumber cnum2(0.8, 0.6);
    ComplexNumber res = cnum1 * cnum2;

    EXPECT_EQ(0.18, res.getRe());
    EXPECT_EQ(0.26, res.getIm());
}

TEST(Silaeva_Natalya_ComplexNumberTest, Can_Sum_Complex_Numbers) {
    double re1 = 2.0;
    double im1 = 0.4;

    ComplexNumber cnum1(2.0, 0.4);

    double re2 = 6.2;
    double im2 = 0.4;

    ComplexNumber cnum2(6.2, 0.4);

    ComplexNumber res = cnum1 + cnum2;

    EXPECT_EQ(8.2, res.getRe());
    EXPECT_EQ(0.8, res.getIm());
}

TEST(Silaeva_Natalya_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    double re1 = 2.0;
    double im1 = 0.4;

    ComplexNumber cnum1(2.0, 0.4);

    double re2 = 6.2;
    double im2 = 0.4;

    ComplexNumber cnum2(6.2, 0.4);

    ComplexNumber res = cnum2 - cnum1;

    EXPECT_EQ(4.2, res.getRe());
    EXPECT_EQ(0.0, res.getIm());
}
