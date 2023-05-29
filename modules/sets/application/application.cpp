// Copyright 2023 Mironov Nikita

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/set_application.h"

int main(int argc, const char** argv) {
    set_application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
