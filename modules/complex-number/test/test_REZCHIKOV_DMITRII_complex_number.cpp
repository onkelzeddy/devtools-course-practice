// Copyright 2023 Rezchikov Dmitrii

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Rezchikov_Dmitrii_Complex_Number, Operation_To_Zero ) {
    ComplexNumber n1(1, 1), n2(-1, -1), zero;
    EXPECT_EQ(zero, (n1 + n2));
}

TEST(Rezchikov_Dmitrii_Complex_Number, Multiply_by_conjugate ) {
    ComplexNumber n1(2, 2), n2(2, -2), expected(8, 0);
    EXPECT_EQ(0, (n1 * n2).getIm());
}

TEST(Rezchikov_Dmitrii_Complex_Number, Conjugate_of_product ) {
    ComplexNumber n1(2, 2), n2(3, 3), n1_c(2, -2), n2_c(3, -3);
    ComplexNumber mult = n1 * n2;  //
    mult.setIm(mult.getIm() * -1);   // conjugate of product
    ComplexNumber mult2 = n1_c * n2_c;  // product of conjugates
    EXPECT_EQ(mult, mult2);
}
