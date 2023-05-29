// Copyright 2023 Popov Andrey

#ifndef MODULES_VOLUMES_INCLUDE_VOLUMES_3D_H_
#define MODULES_VOLUMES_INCLUDE_VOLUMES_3D_H_

#include "Volumes.h"
#include <string>
#include <utility>
class application {
 public:
  struct arguments {
  std::string operation{""};
  };
  std::string operator()(int argc, char** argv);
 private:
  std::string help(const std::string& an);
  bool validate(const std::string& str);
};
double TruncatedCone(const double& Height, const double& BigMajorSemiaxis,
                     const double& BigSmallSemiaxis,
                     const double& SmallMajorSemiaxis,
                     const double& SmallSmallSemiaxis);
double BallSegment(const double& Radius, const double& Height);
double BallSector(const double& BallRadius, const double& SegmentHeight);
double BallLayer(const double& Radius1, const double& Radius2,
                 const double& Height);
double EquilateralPyramid(const double& Height, const double& Side,
                          const int& Edges);
double Tetrahedron(const double& Side);
double Parallelepiped(const double& Side1, const double& Side2,
                      const double& Side3);
double TruncatedCylinder(const double& BigHeight, const double& SmallHeight,
                         const double& MajorSemiaxis,
                         const double& SmallSemiaxis);
double EquilateralPrism(const double& Height, const double& Side,
                        const int& Edges);
double Torus(const double& OuterRadius, const double& InnerRadius);
double Barrel(const double& BallRadius, const double& BarrelRadius);
double Tube(const double& OuterRadius, const double& InnerRadius,
            const double& Height);
double Ellipsoid(const double& MajorSemiaxis, const double& MiddleSemiaxis,
                 const double& SmallSemiaxis);
double EllipticalParaboloid(const double& Height, const double& MajorSemiaxis,
                            const double& SmallSemiaxis);
double EllipticalCone(const double& Height, const double& MajorSemiaxis,
                      const double& SmallSemiaxis);
double EllipticalCylinder(const double& Height, const double& MajorSemiaxis,
                          const double& SmallSemiaxis);
double EquilateralTruncatedPyramid(const double& Height, const double& BigSide,
                                   const double& SmallSide, const int& Edges);
double Octahedron(const double& Side);
double Dodecahedron(const double& Side);
double Icosahedron(const double& Side);
double EquilateralPolyhedron(const int& Edges, const int& Vertexes,
                             const double& Side,
                             const double& DescribedSphereRadius);
double Prizm(const double& Height, const double& Square);
double Pyramid(const double& Height, const double& Square);
double TruncatedPyramid(const double& Height, const double& BigSquare,
                        const double& SmallSquare);

#endif  // MODULES_VOLUMES_INCLUDE_VOLUMES_3D_H_
