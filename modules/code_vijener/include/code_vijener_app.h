// Copyright 2023 Kosterin Alexey

#ifndef MODULES_CODE_VIJENER_INCLUDE_CODE_VIJENER_APP_H_
#define MODULES_CODE_VIJENER_INCLUDE_CODE_VIJENER_APP_H_

#include <string>

class CodeApp {
 public:
     CodeApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string key;
        std::string str;
        int operation;
    } Arguments;
};

#endif  // MODULES_CODE_VIJENER_INCLUDE_CODE_VIJENER_APP_H_
