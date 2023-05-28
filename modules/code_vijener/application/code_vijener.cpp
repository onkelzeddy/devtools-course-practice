// Copyright 2023 Uvarkin Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/code_vijener_application.h"

int main(int argc, const char** argv) {
  CodeVijenerApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
