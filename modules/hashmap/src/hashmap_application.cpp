// Copyright 2023 Eremin Aleksandr

#include "include/hashmap.h"
#include "include/hashmap_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

hashmap_Application::hashmap_Application() : message_("") {}

void hashmap_Application::help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This application is designed to work with hashmap.\n\n" +
        "You can use the following order of arguments to interact with "
        "the table:\n" +
        "  $ " + appname + " <key> <value> <operator>\n\n" +
        "For the operator, you can use:" + "\n\t insert - add record;" +
        "\n\t delete - delete record;" + "\n\t find - find record;" +
        "\n\t count - number of records" + "\n\t print - print the table;";
}

bool hashmap_Application::validatArgumentsStart(int argc, const char** argv) {
    if ((argc - 1) % 3 != 0 || argc < 4) {
        help(argv[0], "ERROR: invalid number of arguments.\n\n");
        return false;
    }
    return true;
}

std::string hashmap_Application::parseKey(const char* arg) {
    std::string Keystring(arg);
    try {
        std::stoi(Keystring);
        return Keystring;
    } catch (...) {
        ProgError = "ERROR: Wrong key format!";
        throw std::string("wrong key format.");
    }
}

double hashmap_Application::parseData(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        ProgError = "ERROR: Wrong value format!";
        throw std::string("Wrong value format!");
    }
    return value;
}

int hashmap_Application::parseOperator(const char* arg) {
    try {
        if (strcmp(arg, "insert") == 0) {
            return 1;
        } else {
            if (strcmp(arg, "delete") == 0) {
                return 2;
            } else {
                if (strcmp(arg, "find") == 0) {
                    return 3;
                } else {
                    if (strcmp(arg, "count") == 0) {
                        return 4;
                    } else {
                        if (strcmp(arg, "print") == 0) {
                            return 5;
                        } else {
                            throw std::string("wrong operator.");
                        }
                    }
                }
            }
        }
    } catch (...) {
        ProgError = "ERROR: Wrong operator!";
        throw std::string("wrong operator.");
    }
}

std::string hashmap_Application::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validatArgumentsStart(argc, argv)) {
        return message_;
    }
    int i = 1;
    while (i < argc - 2) {
        try {
            args.key = parseKey(argv[i]);
            args.value = parseData(argv[i + 1]);
            args.operation = parseOperator(argv[i + 2]);
        } catch (...) {
            return ProgError;
        }
        int count = 0;
        switch (args.operation) {
        case 1:
            try {
                HashMap.InsRecord(args.key, args.value);
                message_ = "The element is inserted by the specified key";
                break;
            } catch (...) {
                return "There is already such an element";
            }
        case 2:
            try {
                HashMap.DelRecord(args.key);
                message_ = "The item has been deleted";
                break;
            } catch (...) {
                return "Record not found";
            }
        case 3:
            if (HashMap.FindRecord(args.key) != nullptr) {
                message_ = "Record found";
                break;
            } else {
                message_ = "Record not found";
                break;
            }
        case 4:
            HashMap.InsRecord(args.key, args.value);
            count = HashMap.GetDataCount();
            message_ = std::to_string(count) + " records found";
            break;
        case 5:
            HashMap.InsRecord(args.key, args.value);
            std::cout << HashMap;
            break;
        }
        i += 3;
    }
    return message_;
}
