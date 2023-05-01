// Copyright 2023 Selivankin Sergey

#pragma once

#include <string>

class CipherApplication {
 public:
    CipherApplication() = default;
    CipherApplication(const CipherApplication &ca) = delete;
    CipherApplication(CipherApplication &&ca) = delete;
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname);
    bool validateArguments(int argc, const char** argv);
    std::string m_message;
};
