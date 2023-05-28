// Copyright 2023 Ustinov Alexandr

#pragma once

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char **argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);

    std::string message_;
    // primes are printed from segment [left_border, right_border]
    unsigned int left_border = 0;
    unsigned int right_border = 0;
};
