#ifndef COMPLEX_SHAPES_HPP
#define COMPLEX_SHAPES_HPP

#include "shape.hpp"
#include <fstream>
#include <memory>
class Rotated : public Shape {
public:
  enum RotationAngle { ninety = 90, oneeighty = 180, twoseventy = 270 };
private:
  RotationAngle _rotationAngle;
  std::unique_ptr<Shape> _shape;
public:
  Rotated(std::unique_ptr<Shape> shape, RotationAngle rotationAngle): _shape(std::move(shape)),_rotationAngle(rotationAngle) {};
  void draw(std::ostream &file) const;
};


#endif