// Copyright 2023 Eremin Aleksandr

#include <iostream>
#include <string>
#include "include/hashmap_application.h"

int main(int argc, const char** argv) {
    hashmap_Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
