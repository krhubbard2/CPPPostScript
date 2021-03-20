#ifndef COMPLEX_SHAPES_HPP
#define COMPLEX_SHAPES_HPP

#include "shape.hpp"
#include <cstdarg>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

class Rotated : public Shape {
public:
  enum RotationAngle { ninety = 90, oneeighty = 180, twoseventy = 270 };

private:
  RotationAngle _rotationAngle;
  std::unique_ptr<Shape> _shape;

public:
  Rotated(std::unique_ptr<Shape> shape, const RotationAngle &rotationAngle)
      : _shape(std::move(shape)), _rotationAngle(rotationAngle){};
  void draw(std::ostream &file) const;
};

class Scaled : public Shape {
private:
  std::unique_ptr<Shape> _shape;
  double _fx;
  double _fy;

public:
  Scaled(std::unique_ptr<Shape> shape, const double &fx, const double &fy)
      : _shape(std::move(shape)), _fx(fx), _fy(fy){};
  void draw(std::ostream &file) const;
};

class Layered : public Shape {
private:
  std::vector<std::shared_ptr<Shape>> _shapes;
public:
  Layered(const std::vector<std::shared_ptr<Shape>> &shapes) {
    _shapes = shapes;
  };
  void draw(std::ostream &file) const;
};

#endif