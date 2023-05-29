// Copyright 2023 Frantcuzov Maksim

#ifndef MODULES_CHECK_SEGMENTS_INTERSECTION_INCLUDE_CHECK_SEGMENTS_APP_H_
#define MODULES_CHECK_SEGMENTS_INTERSECTION_INCLUDE_CHECK_SEGMENTS_APP_H_

#include <string>

class CheckApplication {
 public:
  std::string operator()(int argc, const char **argv);
  std::string printHelp(const std::string &programName);

 private:
  bool argumentsIsValid(int argc, const char **argv);
  std::string Message;
};

#endif  // MODULES_CHECK_SEGMENTS_INTERSECTION_INCLUDE_CHECK_SEGMENTS_APP_H_
