// Copyright 2023 Kolesov Maxim

#include "include/search_application.h"
#include <stdexcept>
#include <vector>
#include "include/binary_search.h"

int parseInt(const char *value) {
  try {
    int integer = std::stoi(value);
    return integer;
  } catch (const std::exception &e) {
    throw std::invalid_argument("Expected integer");
  }
}

size_t parseUInt(const char *value) {
  try {
    int integer = std::stoi(value);
    if (integer < 0) {
      throw std::exception();
    }

    return static_cast<size_t>(integer);
  } catch (const std::exception &e) {
    throw std::invalid_argument("Expected positive integer");
  }
}

void SearchApplication::help(const char *appName) {
  std::string builder;

  // logo
  // terrible format due to cpplint
  builder
.append("#####################################################################")
.append("\n")
.append("#   ____  _                                                  _      #")
.append("\n")
.append("#  | __ )(_)_ __   __ _ _ __ _   _   ___  ___  __ _ _ __ ___| |__   #")
.append("\n")
.append(R"(#  |  _ \| | '_ \ / _` | '__| | | | / __|/ _ \/ _` | '__/ __| '_ \  #)")
.append("\n")
.append(R"(#  | |_) | | | | | (_| | |  | |_| | \__ \  __/ (_| | | | (__| | | | #)")
.append("\n")
.append(R"(#  |____/|_|_| |_|\__,_|_|   \__, | |___/\___|\__,_|_|  \___|_| |_| #)")
.append("\n")
.append("#                            |___/                                  #")
.append("\n")
.append("#####################################################################")
.append("\n\n");

  builder
.append("This is a binary search application").append("\n")
.append("Use this application")
.append(" if you want to find element index in sorted array.")
.append("\n\n")
.append("Please provide arguments in the following format:")
.append("\n\n")
.append("\t$ ")
.append(appName)
.append(" <search element> <array size> <array element> ... <array element>")
.append("\n\n")
.append("Where <array size> is a positive integer")
.append(" and others arguments are integers")
.append("\n");

  m_message = std::move(builder);
}

bool SearchApplication::validateArguments(int argc, const char **argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  }

  if (argc < 4) {
    m_message =
        std::string("[ERROR] Should be at least 4 elements. Type `$ ")
        + argv[0]
        + "` to see help";
    return false;
  }

  size_t size;
  try {
    size = parseUInt(argv[2]);
  } catch (const std::invalid_argument &e) {
    m_message =
        std::string("[ERROR] Can't parse <array size>: ")
        + e.what()
        + ". Type `$ "
        + argv[0]
        + "` to see help";
    return false;
  }

  if (size == 0) {
    m_message =
        std::string("[ERROR] Array must be not empty. Type `$ ") +
        argv[0] +
        "` to see help";
    return false;
  }

  if (size != static_cast<size_t>(argc - 3)) {
    m_message =
        std::string("[ERROR] Elements count doesn't match <array size>.")
        + " Type `$ "
        + argv[0]
        + "` to see help";
    return false;
  }

  return true;
}
std::string SearchApplication::operator()(int argc, const char **argv) {
  if (!validateArguments(argc, argv)) {
    return m_message;
  }

  int target;
  try {
    target = parseInt(argv[1]);
  } catch (const std::invalid_argument &e) {
    m_message =
        std::string("[ERROR] Can't parse <search element>: ")
        + e.what()
        + ". Type `$ "
        + argv[0]
        + "` to see help";
    return m_message;
  }

  std::vector<int> array;
  for (int i = 3; i < argc; i++) {
    int value;
    try {
      value = parseInt(argv[i]);
    } catch (const std::invalid_argument &e) {
      m_message =
          std::string("[ERROR] Can't parse <array element>: ")
          + e.what()
          + ". Type `$ "
          + argv[0]
          + "` to see help";
      return m_message;
    }
    array.push_back(value);
  }

  for (size_t i = 1; i < array.size(); i++) {
    if (array.at(i) < array.at(i-1)) {
      return std::string("[ERROR] Array is not sorted.")
          +" Type `$ "
          + argv[0]
          + "` to see help";
    }
  }

  int result = BinarySearch::find(array, target);

  if (result == -1) {
    return "Element not found";
  }

  return std::string("Find element at ") + std::to_string(result);
}
