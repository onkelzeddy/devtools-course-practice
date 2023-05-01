// Copyright 2023 Tarasova Anastasiya
#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Tarasova_Anastasiya_ComplexNumberTest, Squaring_Im) {
    ComplexNumber num1(0, 1);
    ComplexNumber num2(-1, 0);

    ASSERT_EQ(num1*num1, num2);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Div_By_Zero) {
    ComplexNumber num1(25, 6);
    ComplexNumber num2(0, 0);

    ASSERT_THROW(num1/num2, std::string);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Default_Constructor) {
    ComplexNumber number;

    ASSERT_EQ(number.getIm(), 0);
    ASSERT_EQ(number.getRe(), 0);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Setters) {
    ComplexNumber number;

    number.setRe(8);
    number.setIm(9);

    ASSERT_EQ(number.getRe(), 8);
    ASSERT_EQ(number.getIm(), 9);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Sum_Conjugate) {
    ComplexNumber num1(42, 24);
    ComplexNumber num2(42, -24);

    ComplexNumber num3(84, 0);

    ASSERT_EQ(num1 + num2, num3);
}
