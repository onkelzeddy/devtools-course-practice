// Copyright 2023 Uvarkin Ilya

#include "include/code_vijener.h"
#include "include/code_vijener_application.h"

#include <string>
#include <cstring>

CodeVijenerApplication::CodeVijenerApplication(): _message("") {}

std::string CodeVijenerApplication::operator()(int argc, const char **argv) {
  if (!validateArguments(argc, argv)) {
    return _message;
  }

  Code_vijener Code_vijener(argv[2], argv[3]);
  if (strcmp(argv[1], "encode") == 0) {
    return Code_vijener.Encoder();
  } else {
    return Code_vijener.Decoder();
  }
}

void CodeVijenerApplication::help(const char *appname, const char *message) {
  _message =
          std::string(message) +
          "This is a complex code vijener application.\n\n" +
          "Please provide arguments in the following format:\n\n"+
          " $ " + appname + " <encode|decode> <word> <key> \n\n.";
}

bool CodeVijenerApplication::validateArguments(int argc, const char **argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "ERROR: Should be 3 arguments.\n\n");
    return false;
  }

  if (strcmp(argv[1], "encode") != 0 && strcmp(argv[1], "decode") != 0) {
    help(argv[0], "ERROR: Possible operations only encode or decode.\n\n");
    return false;
  }

  if (!onlyEnglishChars(argv[2]) || !onlyEnglishChars(argv[3])) {
    help(argv[0], "ERROR: should be English characters only.\n\n");
    return false;
  }

  return true;
}

bool CodeVijenerApplication::onlyEnglishChars(const std::string &word) {
  return std::all_of(word.begin(), word.end(),
          [](char ch){ return ch >= 'A' && ch <= 'z'; });
}
