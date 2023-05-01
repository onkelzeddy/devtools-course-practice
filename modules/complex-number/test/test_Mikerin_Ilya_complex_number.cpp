// Copyright 2023 Mikerin Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mikerin_Ilya_ComplexNumberTest, TEST_EQ_OPERATOR) {
  ComplexNumber a(1.1, 2.2),
                b,
                c(1.1, 2.2);
  b = a;

    ASSERT_TRUE(b == c);

  a.setIm(5);

    ASSERT_TRUE(b == c);
}

TEST(Mikerin_Ilya_ComplexNumberTest, TEST_CONSTRUCTOR) {
    ComplexNumber   a(0, 0), b;

    ASSERT_TRUE(b == a);
}

TEST(Mikerin_Ilya_ComplexNumberTest, TEST_DIVISION) {
    ComplexNumber   a(-2, 1),
                    b(1, -1),
                    c(-1.5, -0.5);

    ASSERT_TRUE(a/b == c);
}

TEST(Mikerin_Ilya_ComplexNumberTest, TEST_MULTIPLICATION) {
    ComplexNumber   a(2, 3),
                    b(-1, 1),
                    c(-5, -1);

    ASSERT_TRUE(a*b == c);
}
