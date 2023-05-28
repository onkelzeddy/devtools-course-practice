// Copyright 2023 Uvarkin Ilya

#pragma once

#include <string>

class CodeVijenerApplication {
 public:
    CodeVijenerApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateArguments(int argc, const char** argv);
    bool onlyEnglishChars(const std::string& word);
    std::string _message;
};
