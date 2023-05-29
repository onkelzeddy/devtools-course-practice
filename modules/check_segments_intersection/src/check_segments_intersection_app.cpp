// Copyright 2023 Frantcuzov Maksim

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "include/Point.h"
#include "include/Segment.h"
#include "include/check_segments_app.h"
#include "include/check_segments_intersection.h"

std::string CheckApplication::operator()(int argc, const char **argv) {
  if (argc <= 1 || std::string(argv[1]).empty())
    return printHelp(argv[0]);

  geom::Segment s1{std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3]),
                   std::stod(argv[4])};
  geom::Segment s2{std::stod(argv[5]), std::stod(argv[6]), std::stod(argv[7]),
                   std::stod(argv[8])};

  bool isIntersecting = geom::check_segments_intersection(s1, s2);

  if (isIntersecting) {
    Message += "Segments intersect.\n";
  } else {
    Message += "Segments do not intersect.\n";
  }

  return Message;
}

std::string CheckApplication::printHelp(const std::string &programName) {
  std::stringstream ss;
  ss << "Usage:" << programName << " x1 y1 x2 y2 x3 y3 x4 y4" << std::endl;
  return ss.str();
}
