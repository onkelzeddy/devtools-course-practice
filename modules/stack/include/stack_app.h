// Copyright 2023 Korobeynikova Alice

#pragma once

#include <include/stack.h>

#include <string>

class StackApp {
 public:
  std::string operator()(int argc, const char** argv);

 private:
  std::string message = "";
  void help();
  Stack<int> stack;
};
