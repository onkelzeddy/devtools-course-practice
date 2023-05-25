// Copyright 2023 Kosterin Alexey

#include "include/code_vijener.h"
#include "include/code_vijener_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

CodeApp::CodeApp() : message_("") {}

void CodeApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a code vijener app.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <key> <str> " +
          " <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of 1 - coder, 2 - decoder.\n";
}

bool CodeApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double parseInt(const char* arg) {
    char* end;
    double value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong argument format!");
    }

    return value;
}

std::string CodeApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.key = argv[1];
        args.str = argv[2];
        args.operation = parseInt(argv[3]);
    }
    catch(std::string& str) {
        return str;
    }

    Code_vijener cV;

    cV.SetKey(args.key);
    cV.SetCodeStr(args.str);

    std::ostringstream stream;
    switch (args.operation) {
     case 1:
        stream << "after encoder = " << cV.Encoder();
        break;
     case 2:
         stream << "after Decoder = " << cV.Decoder();
        break;
    }

    message_ = stream.str();

    return message_;
}
