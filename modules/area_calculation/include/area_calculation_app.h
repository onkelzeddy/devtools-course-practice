// Copyright 2023 Goncharova Anna

#ifndef MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_APP_H_
#define MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_APP_H_

#include <string>

class PolygonApp {
 public:
     PolygonApp();
    std::string operator()(int argc, const char** argv);
 private:
    std::string reference(const std::string& appname);
    std::string error();
};

#endif  // MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_APP_H_
