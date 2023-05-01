// Copyright 2023 Kolesov Maxim

#include "include/search_application.h"

int main(int argc, const char **argv) {
  SearchApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
