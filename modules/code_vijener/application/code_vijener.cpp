// Copyright 2023 Kosterin Alexey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/code_vijener_app.h"

int main(int argc, const char** argv) {
    CodeApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
