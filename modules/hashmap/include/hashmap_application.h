// Copyright 2023 Eremin Aleksandr

#ifndef MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_
#define MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_

#include <string>
#include "include/hashmap.h"

class hashmap_Application {
 public:
    hashmap_Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validatArgumentsStart(int argc, const char** argv);
    std::string parseKey(const char* arg);
    double parseData(const char* arg);
    int parseOperator(const char* arg);
    std::string message_;
    std::string ProgError = "ERROR: Strange Error";
    hashmap HashMap;
    typedef struct {
        std::string key;
        double value;
        char operation;
    } Arguments;
};

#endif  // MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_
