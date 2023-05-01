// Copyright 2023 Kosterin Alexey

#include <gtest/gtest.h>
#include <include/complex_number.h>

TEST(kosterin_a_ComplexNumberTest, Can_Create_Complex_Number) {
    double real = 5.0;
    double image = 0.1;

    ASSERT_NO_THROW(ComplexNumber comNum(real, image));
}

TEST(kosterin_a_ComplexNumberTest, True_Real_Image_Number) {
    double real = 5.0;
    double image = 0.1;
    ComplexNumber comNum(real, image);
    EXPECT_EQ(real, comNum.getRe());
    EXPECT_EQ(image, comNum.getIm());
}

TEST(kosterin_a_ComplexNumberTest, Test_Default_Constructor) {
    ASSERT_NO_THROW(ComplexNumber comNum());
}
TEST(kosterin_a_ComplexNumberTest, Test_Copie_Constructor) {
    double real = 2.0;
    double image = 0.1;
    ComplexNumber comNum1(real, image);
    ComplexNumber comNum2(comNum1);
    EXPECT_EQ(comNum1, comNum2);
}

TEST(kosterin_a_ComplexNumberTest, Test_Sum_Complex_Number) {
    ComplexNumber comNum1(5.0, 0.2);
    ComplexNumber comNum2(2.0, 0.5);
    ComplexNumber comNumRes(7.0, 0.7);
    ASSERT_EQ(comNumRes, comNum1 + comNum2);
}

TEST(kosterin_a_ComplexNumberTest, Test_Multiply_Complex_Number) {
    ComplexNumber comNum1(0.3, 0.1);
    ComplexNumber comNum2(0.8, 0.6);
    ComplexNumber comNumRes(0.18, 0.26);
    EXPECT_EQ(comNumRes, comNum1* comNum2);
}

TEST(kosterin_a_ComplexNumberTest, Test_Compare_Complex_Number) {
    ComplexNumber comNum1(5.0, 0.5);
    ComplexNumber comNum2(2.0, 0.2);
    EXPECT_TRUE(comNum1 != comNum2);
}
