// Copyright 2023 Ivlev Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ivlev_ComplexNumberTest, Test_can_create_0_ComplexNumber) {
    ASSERT_NO_THROW(ComplexNumber z);

    ComplexNumber z;
    EXPECT_DOUBLE_EQ(z.getRe(), 0);
    EXPECT_DOUBLE_EQ(z.getIm(), 0);
}

TEST(Ivlev_ComplexNumberTest, Test_can_create_ComplexNumber) {
    double real = -2.5, im = 2.5;

    ASSERT_NO_THROW(ComplexNumber z(real, im));

    ComplexNumber z(real, im);
    EXPECT_DOUBLE_EQ(z.getRe(), -2.5);
    EXPECT_DOUBLE_EQ(z.getIm(), 2.5);
}

TEST(Ivlev_ComplexNumberTest, Test_EQ_ComplexNumber) {
    double real = -2.5, im = 2.5;

    ComplexNumber z(real, im);
    ComplexNumber z_(real, im);
    EXPECT_EQ(z, z_);
}

TEST(Ivlev_ComplexNumberTest, Test_NE_ComplexNumber) {
    double real = -2.5;

    ComplexNumber z(real, -2.5);
    ComplexNumber z_(real, 2.5);
    EXPECT_NE(z, z_);
}

TEST(Ivlev_ComplexNumberTest, Test_can_copy_ComplexNumber) {
    double real = -2.5, im = 2.5;

    ComplexNumber z(real, im);
    ComplexNumber z_copy(z);
    EXPECT_EQ(z, z_copy);
}

TEST(Ivlev_ComplexNumberTest, Test_div_by_zero_ComplexNumber) {
    ComplexNumber z(1, -2);
    ComplexNumber z_0(std::numeric_limits<double>::epsilon()/2, 0);
    ASSERT_ANY_THROW(z/z_0);
}

TEST(Ivlev_ComplexNumberTest, Test_sum_ComplexNumber) {
    ComplexNumber z1(1, -2);
    ComplexNumber z2(-2, 1);
    ComplexNumber answer(-1, -1);

    EXPECT_EQ(answer, z1+z2);
}

TEST(Ivlev_ComplexNumberTest, Test_sub_ComplexNumber) {
    ComplexNumber z1(2, -2);
    ComplexNumber z2(-2, 2);
    ComplexNumber answer(4, -4);

    EXPECT_EQ(answer, z1-z2);
}


TEST(Ivlev_ComplexNumberTest, Test_mul_ComplexNumber) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(1, -1);
    ComplexNumber answer(3, 1);

    EXPECT_EQ(answer, z1*z2);
}

TEST(Ivlev_ComplexNumberTest, Test_div_ComplexNumber) {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(0, -1);
    ComplexNumber answer(-2, 1);

    EXPECT_EQ(answer, z1/z2);
}
