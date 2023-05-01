// Copyright 2023 Korobeynikova Alice

#include "include/stack_app.h"

void StackApp::help() {
  message += "This is an integer stack application.\n\n";
  message += "Parameters:\n";
  message += "s \t\t Output size of stack.\n";
  message += "e \t\t Output if stack is empty.\n";
  message += "t \t\t Output top element of stack.\n";
  message += "pop \t\t Pop element from stack.\n";
  message += "push <values> \t Input element(s) and push it into stack.\n";
  message += "c \t\t Clear stack.\n\n";
}

std::string StackApp::operator()(int argc, const char** argv) {
  if (argc == 1) {
    help();
  }

  for (int i = 1; i < argc; ++i) {
    if (i != 1) message += " ";
    std::string key(argv[i]);
    if (key == "s") {
      message += std::to_string(stack.size());
    } else if (key == "e") {
      message += (stack.empty() ? std::string("true") : std::string("false"));
    } else if (key == "t") {
      try {
        message += std::to_string(stack.top());
      } catch (const std::out_of_range&) {
        message += "error: can't get top, stack is empty";
      }
    } else if (key == "pop") {
      try {
        stack.pop();
      } catch (const std::out_of_range&) {
        message += "error: can't pop, stack is empty";
      }
    } else if (key == "push") {
      for (++i; i < argc && (std::isdigit(*argv[i]) || *argv[i] == '-'); ++i) {
        stack.push(atoi(argv[i]));
      }
      --i;
    } else if (key == "c") {
      stack.clear();
    } else {
      message += "error: unknown key " + key;
    }
  }
  message += '\n';
  return message;
}
