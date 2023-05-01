// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Antonova_A_complex_number, Substraction) {
  ComplexNumber z1(10.0, 5.0);
  ComplexNumber z2(2.0, 3.0);

  ComplexNumber z1_Sub_z2 = z1 - z2;

  EXPECT_EQ(z1_Sub_z2, ComplexNumber(8.0, 2.0));
}

TEST(Antonova_A_complex_number, Sum) {
  ComplexNumber z1(1.0, 0.0);
  ComplexNumber z2(0.0, 1.0);

  ComplexNumber z1_plus_z2 = z1 + z2;

  EXPECT_EQ(z1_plus_z2, ComplexNumber(1.0, 1.0));
}

TEST(Antonova_A_complex_number, Multiply) {
  ComplexNumber z1(5.0, 5.0);
  ComplexNumber z2(3.0, 3.0);

  ComplexNumber z1_M_z2 = z1 * z2;

  EXPECT_EQ(z1_M_z2, ComplexNumber(0, 30));
}
