// Copyright 2023 Semenova Veronika

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Semenova_Veronika_ComplexNumberTest,
    Create_complex_number_with_parameters_correctly) {
    ComplexNumber a(1.25, -2.0);
    ASSERT_EQ(a.getRe(), 1.25);
    ASSERT_EQ(a.getIm(), -2.0);
}

TEST(Semenova_Veronika_ComplexNumberTest,
    Can_assign_two_complex_number) {
    ComplexNumber a, b;
    ASSERT_NO_THROW(a = b);
}

const double Eps = 0.0000001;
TEST(Semenova_Veronika_ComplexNumberTest,
    Div_complex_number_with_specified_accuracy) {
    ComplexNumber a(1.0, 1.0);
    ComplexNumber b(3.0, 3.0);
    ComplexNumber c = a / b;

    ASSERT_NEAR(c.getRe(), 1.0 / 3.0, Eps);
    ASSERT_NEAR(c.getIm(), 0.0, Eps);
}
