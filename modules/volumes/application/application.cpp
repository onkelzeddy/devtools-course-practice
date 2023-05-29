// Copyright 2023 Popov Andrey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Volumes_3d.h"

int main(int argc, char** argv) {
    application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
