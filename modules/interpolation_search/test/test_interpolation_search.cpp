// Copyright 2023 Mironov Nikita
#include <gtest/gtest.h>

#include "include/interpolation_search.h"

TEST(Iterpolation_search_test, Class_can_be_created) {
    std::vector<int> test_vector = {1, 3, 5, 8};
    ASSERT_NO_THROW(interpolationSearch is(test_vector));
}

TEST(Iterpolation_search_test, Class_throw_error_on_empty_vector) {
    std::vector<int> test_vector;
    ASSERT_ANY_THROW(interpolationSearch is(test_vector));
}

TEST(Iterpolation_search_test, You_can_set_new_vector) {
    std::vector<int> test_vector = {1, 3, 5, 8};
    interpolationSearch is(test_vector);

    test_vector = {1, 2, 1, 9};
    ASSERT_NO_THROW(is.set_vector(test_vector));
}

TEST(Iterpolation_search_test, You_can_not_set_new_empty_vector) {
    std::vector<int> test_vector = {1, 3, 5, 8};
    interpolationSearch is(test_vector);

    std::vector<int> empty_test_vector;
    ASSERT_NO_THROW(is.set_vector(empty_test_vector));
}

TEST(Iterpolation_search_test, Search_in_sorted_vector) {
    std::vector<int> test_vector = {1, 3, 5, 8, 9};
    interpolationSearch is(test_vector);

    int search_target = 6;
    int expected_search_result = -1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Search_in_unsorted_vector) {
    std::vector<int> test_vector = {9, 1, 6, 2, 1, 7};
    interpolationSearch is(test_vector);

    int search_target = 5;
    int expected_search_result = -1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_vector) {
    std::vector<int> test_vector = {1, 2, 7, 12, 25, 27};
    interpolationSearch is(test_vector);

    int search_target = 2;
    int expected_search_result = 1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_unsorted_vector) {
    std::vector<int> test_vector = {9, 1, 6, 2, 1, 7};
    interpolationSearch is(test_vector);

    int search_target = 2;
    int expected_search_result = 2;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Search_in_one_element_vector) {
    std::vector<int> test_vector = {9};
    interpolationSearch is(test_vector);

    int search_target = 2;
    int expected_search_result = -1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_one_element_vector) {
    std::vector<int> test_vector = {6};
    interpolationSearch is(test_vector);

    int search_target = 6;
    int expected_search_result = 0;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Search_in_sorted_negative_vector) {
    std::vector<int> test_vector = {-5, -4, -3, -2, -1};
    interpolationSearch is(test_vector);

    int search_target = 1;
    int expected_search_result = -1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_negative_vector) {
    std::vector<int> test_vector = {-5, -4, -3, -2, -1};
    interpolationSearch is(test_vector);

    int search_target = -4;
    int expected_search_result = 1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Search_in_unsorted_negative_vector) {
    std::vector<int> test_vector = {-4, -3, -5, -2, -1};
    interpolationSearch is(test_vector);

    int search_target = -10;
    int expected_search_result = -1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_unsorted_negative_vector) {
    std::vector<int> test_vector = {-4, -3, -5, -2, -1};
    interpolationSearch is(test_vector);

    int search_target = -3;
    int expected_search_result = 2;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Search_in_sorted_mixed_vector) {
    std::vector<int> test_vector = {-5, -4, -3, -2, -1, 1, 2, 12, 23};
    interpolationSearch is(test_vector);

    int search_target = 23;
    int expected_search_result = -1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_mixed_vector) {
    std::vector<int> test_vector = {-5, -4, -3, -2, -1, 1, 2, 12, 23};
    interpolationSearch is(test_vector);

    int search_target = -2;
    int expected_search_result = 3;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Search_in_unsorted_mixed_vector) {
    std::vector<int> test_vector = {-5, -4, 2, -2, -1, -3, 1, 23, 12};
    interpolationSearch is(test_vector);

    int search_target = 25;
    int expected_search_result = -1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_unsorted_mixed_vector) {
    std::vector<int> test_vector = {-5, -4, 2, -2, -1, -3, 1, 23, 12};
    interpolationSearch is(test_vector);

    int search_target = -2;
    int expected_search_result = 3;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}
