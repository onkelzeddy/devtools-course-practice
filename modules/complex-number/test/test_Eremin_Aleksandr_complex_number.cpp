// Copyright 2023 Eremin Aleksandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Eremin_Aleksandr_ComplexNumberTest,
    Correctly_creates_ComplexNumber_equal_to_zero) {
    ComplexNumber z;
    EXPECT_DOUBLE_EQ((z.getRe()), 0.0);
    EXPECT_DOUBLE_EQ((z.getIm()), 0.0);
}

TEST(Eremin_Aleksandr_ComplexNumberTest, Can_set_only_Re) {
    ComplexNumber z;
    double re = 1.12;
    z.setRe(re);
    EXPECT_EQ(re, z.getRe());
}

TEST(Eremin_Aleksandr_ComplexNumberTest, Can_get_Im) {
    ComplexNumber number(12, 34);
    const double im = number.getIm();
    ASSERT_EQ(im, 34);
}

TEST(Eremin_Aleksandr_ComplexNumberTest, Can_assign_two_complex_number) {
    ComplexNumber a, b;
    ASSERT_NO_THROW(a = b);
}

TEST(Eremin_Aleksandr_ComplexNumberTest, Can_Sum_Complex_Numbers) {
    double re1 = 2.0;
    double im1 = 1.234;

    ComplexNumber z1(re1, im1);

    double re2 = 12.0;
    double im2 = 5.678;
    ComplexNumber z2(re2, im2);
    ComplexNumber sum = z1 + z2;
    EXPECT_EQ(14, sum.getRe());
    EXPECT_EQ(6.912, sum.getIm());
}
