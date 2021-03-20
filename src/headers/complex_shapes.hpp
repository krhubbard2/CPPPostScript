#ifndef COMPLEX_SHAPES_HPP
#define COMPLEX_SHAPES_HPP

#include "shape.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

class Rotated : public Shape {
public:
  enum RotationAngle { ninety = 90, oneeighty = 180, twoseventy = 270 };

private:
  RotationAngle _rotationAngle;
  std::shared_ptr<Shape> _shape;

public:
  Rotated(std::shared_ptr<Shape> shape, const RotationAngle &rotationAngle)
      : _shape(shape), _rotationAngle(rotationAngle){
        setHeight(shape->getHeight());
        setWidth(shape->getWidth());
      };
  void draw(std::ostream &file) const;
};

class Scaled : public Shape {
private:
  std::shared_ptr<Shape> _shape;
  double _fx;
  double _fy;

public:
  Scaled(std::shared_ptr<Shape> shape, const double &fx, const double &fy)
      : _shape(shape), _fx(fx), _fy(fy){
        setWidth(shape->getWidth() * fx);
        setHeight(shape->getHeight() * fy);
      };
  void draw(std::ostream &file) const;
};

class Layered : public Shape {
private:
  std::vector<std::shared_ptr<Shape>> _shapes;

public:
  Layered(const std::vector<std::shared_ptr<Shape>> &shapes);
  void draw(std::ostream &file) const;
};

class Vertical : public Shape {
private:
  std::vector<std::shared_ptr<Shape>> _shapes;

public:
  Vertical(const std::vector<std::shared_ptr<Shape>> &shapes);
  void draw(std::ostream &file) const;
};

class Horizontal : public Shape {
private:
  std::vector<std::shared_ptr<Shape>> _shapes;

public:
  Horizontal(const std::vector<std::shared_ptr<Shape>> &shapes);
  void draw(std::ostream &file) const;
};
#endif