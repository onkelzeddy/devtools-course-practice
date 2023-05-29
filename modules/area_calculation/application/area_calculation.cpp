// Copyright 2023 Goncharova Anna

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/area_calculation_app.h"

int main(int argc, const char** argv) {
    PolygonApp application;
    std::string out = application(argc, argv);
    std::cout << out << std::endl;
    return 0;
}
