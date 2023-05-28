// Copyright 2023 Ustinov Alexands

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/prime_numbers_from_interval_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
