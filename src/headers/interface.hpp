#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "basic_shapes.hpp"
#include "complex_shapes.hpp"
#include "unique_shapes.hpp"
#include <fstream>
#include <iostream>

void setCursor(std::ostream &file, const double &x, const double &y);
std::shared_ptr<Circle> makeCircle(const double &radius);
std::shared_ptr<Polygon> makePolygon(const int &numSides, const double &sideLength);
std::shared_ptr<Triangle> makeTriangle(const double &sideLength);
std::shared_ptr<Rectangle> makeRectangle(const double &width, const double &height);
std::shared_ptr<Spacer> makeSpacer(const double &width, const double &height);
std::shared_ptr<Square> makeSquare(const double &sideLength);

std::shared_ptr<Scaled> makeScaled(std::shared_ptr<Shape> shape,  const double &fx, const double &fy);
std::shared_ptr<Rotated> makeRotated(std::shared_ptr<Shape> shape, const Rotated::RotationAngle &angle);
std::shared_ptr<Layered> makeLayered(const std::vector<std::shared_ptr<Shape>> &shapes);
std::shared_ptr<Horizontal> makeHorizontal(const std::vector<std::shared_ptr<Shape>> &shapes);
std::shared_ptr<Vertical> makeVertical(const std::vector<std::shared_ptr<Shape>> &shapes);

std::shared_ptr<Hamburger> makeHamburger(const int &patties, const int &cheese, const int &lettuce);
#endif