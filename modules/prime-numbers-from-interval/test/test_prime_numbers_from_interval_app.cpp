// Copyright 2023 Ustinov Alexandr

#include <gtest/gtest.h>

#include <string>
#include "../include/prime_numbers_from_interval_app.h"

TEST(Ustinov_test_prime_numbers_from_interval_app, no_arguments) {
    Application app;
    // simulation of command prompt arguments
    int argc = 1;
    const char *argv[1]{""};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line,
        "This applicaion prints prime numbers from given interval.");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, less_than_2_arguments) {
    Application app;
    // simulation of command prompt arguments
    int argc = 2;
    const char *argv[2] = {"", "first_arg"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "ERROR: Should be 2 arguments.");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, more_than_2_arguments) {
    Application app;
    // simulation of command prompt arguments
    int argc = 4;
    const char *argv[4] = {"", "first_arg", "second_arg", "third_arg"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "ERROR: Should be 2 arguments.");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, incorrect_arguments_1) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "not_a_number_1", "not_a_number_2"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Wrong number format!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, incorrect_arguments_2) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "0", "not_a_number"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Wrong number format!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, incorrect_arguments_3) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "not_a_number", "3"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Wrong number format!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, incorrect_arguments_4) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "1.0", "3.0"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Wrong number format!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, negative_borders_1) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "-1", "-2"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Borders must be positive integers!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, negative_borders_2) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "-1", "3"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Borders must be positive integers!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, negative_borders_3) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "0", "-1"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Borders must be positive integers!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, right_less_than_left) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "3", "0"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Left border is greater than right border!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, border_uint_overflow) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "3", "200000000000"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Border is very big!");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, correct_borders_1) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "0", "1"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Primes from the interval [0, 1]: ");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, correct_borders_2) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "2", "2"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Primes from the interval [2, 2]: 2 ");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, correct_borders_3) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "2", "11"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Primes from the interval [2, 11]: 2 3 5 7 11 ");
}

TEST(Ustinov_test_prime_numbers_from_interval_app, first_carmichael_number) {
    Application app;
    // simulation of command prompt arguments
    int argc = 3;
    const char *argv[3] = {"", "561", "561"};

    std::string app_output = app(argc, argv);
    // first line of application output string
    std::string first_line = app_output.substr(0,
        app_output.find_first_of('\n'));

    EXPECT_EQ(first_line, "Primes from the interval [561, 561]: ");
}
