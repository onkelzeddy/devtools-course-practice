// Copyright 2023 Goncharova Anna

#include <gtest/gtest.h>
#include "include/vector_3d.h"

TEST(Vector3d, can_create_vector_3d_without_parameters) {
    ASSERT_NO_THROW(Vector3d vec);
}

TEST(Vector3d, vector_3d_without_parameters_is_null) {
    Vector3d vec;

    EXPECT_TRUE(vec[0] == 0.0 &&
        vec[1] == 0.0 && vec[2] == 0.0);
}

TEST(Vector3d, can_create_vector_3d_with_parameters) {
    ASSERT_NO_THROW(Vector3d(1.0, 2.0, 3.0));
}

TEST(Vector3d, can_get_coord) {
    Vector3d vec(1.0, 2.0, 3.0);

    EXPECT_DOUBLE_EQ(vec[1], 2.0);
}

TEST(Vector3d, can_set_coord) {
    Vector3d vec;

    vec[2] = 2.5;

    EXPECT_DOUBLE_EQ(vec[2], 2.5);
}

TEST(Vector3d, can_get_coord_from_const_vector_3d) {
    const Vector3d vec(1.0, 2.0, 3.0);

    EXPECT_DOUBLE_EQ(vec[0], 1.0);
}

TEST(Vector3d, cannot_get_coord_out_of_range) {
    Vector3d vec(1.0, 2.0, 3.0);

    ASSERT_ANY_THROW(vec[6]);
}

TEST(Vector3d, cannot_get_coord_out_of_range_from_const_vector_3d) {
    const Vector3d vec(1.0, 2.0, 3.0);

    ASSERT_ANY_THROW(vec[-2]);
}

TEST(Vector3d, cannot_set_coord_out_of_range) {
    Vector3d vec(1.0, 2.0, 3.0);

    ASSERT_ANY_THROW(vec[6] = 3.0);
}

TEST(Vector3d, can_get_norma_of_vector_3d) {
    Vector3d vec(2.0, 6.0, 3.0);

    double norma = vec.get_norma();

    EXPECT_NEAR(norma, 7, 1e-10);
}

TEST(Vector3d, can_get_normalization_of_not_null_vector_3d) {
    Vector3d vec(2.0, 6.0, 3.0);
    Vector3d expect_ans(2.0 / 7.0, 6.0 / 7.0, 3.0 / 7.0);

    Vector3d ans = vec.get_normalization();

    EXPECT_TRUE(ans[0] == expect_ans[0] &&
        ans[1] == expect_ans[1] && ans[2] == expect_ans[2]);
}

TEST(Vector3d, cannot_get_normalization_of_null_vector_3d) {
    Vector3d vec;

    ASSERT_ANY_THROW(vec.get_normalization());
}

TEST(Vector3d, can_count_scalar_mult) {
    Vector3d vec1(1.5, 5.3, 3.0);
    Vector3d vec2(0.1, -4.0, 6.0);

    double ans_of_scalar_mult = vec1.scalar_mult(vec1, vec2);

    EXPECT_DOUBLE_EQ(ans_of_scalar_mult, -3.05);
}

TEST(Vector3d, can_count_vector_mult) {
    Vector3d vec1(1.0, 5.5, 3.0);
    Vector3d vec2(0.4, -4.0, 6.0);
    Vector3d expect_ans(45.0, -4.8, -6.2);

    Vector3d ans = vec1.vector_mult(vec1, vec2);
    EXPECT_TRUE(ans[0] == expect_ans[0] &&
        ans[1] == expect_ans[1] && ans[2] == expect_ans[2]);
}
