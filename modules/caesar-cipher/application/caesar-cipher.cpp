// Copyright 2023 Selivankin Sergey

#include "include/cipher_application.h"

int main(int argc, const char** argv) {
    CipherApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
