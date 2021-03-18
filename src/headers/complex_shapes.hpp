#ifndef COMPLEX_SHAPES_HPP
#define COMPLEX_SHAPES_HPP

#include "shape.hpp"
#include <fstream>
#include <memory>
#include <iostream>
#include <vector>
#include <initializer_list>

class Rotated : public Shape {
public:
  enum RotationAngle { ninety = 90, oneeighty = 180, twoseventy = 270 };
private:
  RotationAngle _rotationAngle;
  std::unique_ptr<Shape> _shape;
public:
  Rotated(std::unique_ptr<Shape> shape, const RotationAngle &rotationAngle): _shape(std::move(shape)),_rotationAngle(rotationAngle) {};
  void draw(std::ostream &file) const;
};

class Scaled : public Shape {
private:
  std::unique_ptr<Shape> _shape;
  double _fx;
  double _fy;
public:
  Scaled(std::unique_ptr<Shape> shape, const double &fx, const double &fy) : _shape(std::move(shape)), _fx(fx), _fy(fy) {};
  void draw(std::ostream &file) const;
};

class Layered : public Shape {
  private:
    //std::vector<std::unique_ptr<Shape>> _shapes;
    std::vector<std::reference_wrapper<const Shape>> _shapeRef;
  public:
    Layered(std::vector<std::reference_wrapper<Shape>> *shapeRef) : _shapeRef(std::move(shapeRef)) {}
    
    // Layered(std::initializer_list<Shape> shapes){ 
    //   for(const auto & shape: shapes) {
    //     std::cout << shape.getHeight() << std::endl;
    //   }
    // };
    void draw(std::ostream &file) const {};
};

#endif