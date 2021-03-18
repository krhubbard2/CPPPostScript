#ifndef COMPLEX_SHAPES_HPP
#define COMPLEX_SHAPES_HPP

#include "shape.hpp"
#include <fstream>

class Rotated : public Shape {
private:
  double _radius;

public:
  enum RotationAngle { ninety = 90, oneeighty = 180, twoseventy = 270 };
  Rotated(Shape &shape, RotationAngle rotationAngle);
  void draw(std::ofstream &file) const;
};
#endif