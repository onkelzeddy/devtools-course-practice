// Copyright 2023 Ustinov Alexandr

#include "../include/prime_numbers_from_interval.h"
#include "../include/prime_numbers_from_interval_app.h"

#include <sstream>
#include <cstdint>
#include <limits>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This applicaion prints prime numbers from given interval.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <left_border> <right_border>\n\n" +

          "<left_border> and <right_border> are non-negative integers,\n" +
          "no floating points are allowed,\n" +
          "<left_border> must be less or equal to <right_border>.\n\n" +
          "Example:\n\n" +
          "  $ app_name 2 11\n\n" +
          "The output should be:\n\n" +
          "Primes from the interval [2, 11]: 2 3 5 7 11 ";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        // the only 2 arguments are left and right borders
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

unsigned int parseUnsignedInt(const char* arg) {
    // 'end' points to terminating zero of source string
    // if convertion was successful OR points to the beginning
    // of source string if it wasn't successful
    char* end;

    // use int64_t to avoid problems with 'strtoll'
    // and negative borders from input
    int64_t value = strtoll(arg, &end, 10);
    constexpr int64_t uint32_max = static_cast<int64_t>(
        std::numeric_limits<unsigned int>::max());

    // check if convertion is successful
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    // negative borders aren't allowed
    if (value < 0) {
        throw std::string("Borders must be positive integers!");
    }
    // 'primality_test_interval' takes 'unsigned int' arguments
    // so we have to make sure 'value' doesn't exceed upper bound
    if (value > uint32_max) {
        throw std::string("Border is very big!");
    }

    return static_cast<unsigned int>(value);
}

std::string Application::operator()(int argc, const char** argv) {
    // check that there are no arguments or exactly 2 arguments
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        left_border = parseUnsignedInt(argv[1]);
        right_border = parseUnsignedInt(argv[2]);

        if (left_border > right_border)
            throw std::string("Left border is greater than right border!");
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream ostream;
    std::vector<unsigned int> primes_from_interval = primality_test_interval(
        left_border, right_border);

    ostream << "Primes from the interval [" << left_border << ", "
           << right_border << "]: ";
    for (unsigned int prime : primes_from_interval)
        ostream << prime << ' ';

    message_ = ostream.str();

    return message_;
}
