#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "basic_shapes.hpp"
#include "complex_shapes.hpp"
#include <fstream>
#include <iostream>

void setCursor(std::ostream &file, double x, double y);
std::shared_ptr<Circle> makeCircle(double radius);
std::shared_ptr<Polygon> makePolygon(const int &numSides, const double &sideLength);
std::shared_ptr<Triangle> makeTriangle(const double &sideLength);
std::shared_ptr<Rectangle> makeRectangle(const double &width, const double &height);
std::shared_ptr<Spacer> makeSpacer(const double &width, const double &height);
std::shared_ptr<Square> makeSquare(const double &sideLength);

// std::shared_ptr<Rotated> makeRotated(std::shared_ptr<Shape> shape, const RotationAngle &rotationAngle);
std::shared_ptr<Scaled> makeScaled(std::shared_ptr<Shape> shape, const double &scaleFactor);
#endif