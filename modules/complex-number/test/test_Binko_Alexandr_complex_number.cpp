// Copyright 2023 Alexandr Binko

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Binko_Alexandr_ComplexNumberTest, TEST_Get_Set) {
  ComplexNumber a(5.0, 7.0);

  a.setRe(2.5);
  a.setIm(9.0);

  ASSERT_EQ(a.getRe(), 2.5);
  ASSERT_EQ(a.getIm(), 9.0);
}

TEST(Binko_Alexandr_ComplexNumberTest, TEST_Sum) {
  ComplexNumber a(4.0, 9.0),
                b(3.0, 5.0),
                expected(7.0, 14.0);

  ComplexNumber result = a + b;

  ASSERT_EQ(result, expected);
}


TEST(Binko_Alexandr_ComplexNumberTest, TEST_Subt) {
  ComplexNumber a(4.0, 9.0),
                b(3.0, 5.0),
                expected(1.0, 4.0);

  ComplexNumber result = a - b;

  ASSERT_EQ(result, expected);
}
