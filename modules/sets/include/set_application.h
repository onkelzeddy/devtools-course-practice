// Copyright 2023 Mironov Nikita

#ifndef MODULES_SETS_INCLUDE_SET_APPLICATION_H_
#define MODULES_SETS_INCLUDE_SET_APPLICATION_H_

#include <string>
#include <vector>

#include "include/set.h"

class set_application {
 public:
    void help();
    std::string operator()(int argc, const char** argv);
 private:
    bool is_number(const std::string& string);
    std::string message;
    Set set;
};

#endif  // MODULES_SETS_INCLUDE_SET_APPLICATION_H_
