// Copyright 2023 Makarov Danila

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Makarov_Danila_ComplexNumberTest, TEST_NE_AND_EQ) {
  ComplexNumber a(1.1, 2.2),
                b(1.0, 2.0),
                c(1.1, 2.2);
  ASSERT_NE(a, b);
  ASSERT_EQ(a, c);
}

TEST(Makarov_Danila_ComplexNumberTest, TEST_SUM) {
  ComplexNumber a(1234.0, 12.0),
                b(766.0, 11.0),
                expected(2000.0, 23.0);

  ComplexNumber result = a + b;

  ASSERT_EQ(expected, result);
}

TEST(Makarov_Danila_ComplexNumberTest, TEST_SUB) {
  ComplexNumber a(123.0, 50.0),
                b(30.0, 14.0),
                expected(93.0, 36.0);

  ComplexNumber result = a - b;

  ASSERT_EQ(expected, result);
}

TEST(Makarov_Danila_ComplexNumberTest, TEST_MULT) {
  ComplexNumber a(10.0, 17.0),
                b(88.0, 3.0),
                expected(829.0, 1526.0);

  ComplexNumber result = a * b;

  ASSERT_EQ(expected, result);
}
