// Copyright 2023 Goncharova Anna

#include "include/area_calculation.h"
#include "include/area_calculation_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <sstream>
#include <utility>

PolygonApp::PolygonApp() {}

std::string PolygonApp::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return this->reference(argv[0]);
    }
    if (((argc < 7) && (argc > 2)) || (argc % 2 == 0))
       return this->error();

    Polygon polygon;
    std::string message;
    std::ostringstream stream;
    try {
        for (int i = 1; i < argc; i = i + 2) {
            double x, y;
            std::string p_x = argv[i];
            std::string p_y = argv[i + 1];

            x = std::stod(p_x);
            y = std::stod(p_y);
            std::pair<double, double> temp(x, y);
            polygon.addPoint(temp);
        }
        stream << polygon.countArea();
    }
    catch (std::exception const& e) {
        stream << "Coordinates do not exist";
    }

    message = stream.str();
    return message;
}

std::string PolygonApp::reference(const std::string& appname) {
    std::string reference = std::string("")
        + "Polygon area calculation. \n"
        + "Enter the points of the polygon: \n"
        + "Enter the coordinates of the points anticlockwise \n"
        + "First, enter the x coordinate, \n"
        + "Next enter space and the y coordinate, and also for all points.";
    return reference;
}

std::string PolygonApp::error() {
    std::string error = std::string("")
        + "Wrong argument sum, try --reference";
    return error;
}
