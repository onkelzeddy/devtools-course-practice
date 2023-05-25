// Copyright 2023 Mironov Nikita
#include <gtest/gtest.h>

#include "include/interpolation-search.h"

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

    std::vector<int> empty_test_vector = {};
    ASSERT_ANY_THROW(is.set_vector(empty_test_vector));
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

TEST(Iterpolation_search_test, Successful_search_in_sorted_vector_1) {
    std::vector<int> test_vector = {1, 2, 7, 12, 25, 27};
    interpolationSearch is(test_vector);

    int search_target = 2;
    int expected_search_result = 1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_vector_2) {
    std::vector<int> test_vector = {1, 2, 7, 12, 25, 27};
    interpolationSearch is(test_vector);

    int search_target = 25;
    int expected_search_result = 4;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_vector_3) {
    std::vector<int> test_vector = {1, 2, 7, 12, 25, 27, 29};
    interpolationSearch is(test_vector);

    int search_target = 12;
    int expected_search_result = 3;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_vector_4) {
    std::vector<int> test_vector = {1, 2, 7, 12, 25, 27, 29};
    interpolationSearch is(test_vector);

    int search_target = 29;
    int expected_search_result = 6;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_vector_5) {
    std::vector<int> test_vector = {27, 29};
    interpolationSearch is(test_vector);

    int search_target = 29;
    int expected_search_result = 1;

    ASSERT_EQ(expected_search_result, is.search(search_target));
}

TEST(Iterpolation_search_test, Successful_search_in_sorted_vector_6) {
    std::vector<int> test_vector =
        {1, 2, 7, 12, 25, 27, 29, 30, 37, 42, 48, 53, 55};
    interpolationSearch is(test_vector);

    int search_target = 7;
    int expected_search_result = 2;

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
