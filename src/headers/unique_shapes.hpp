#ifndef UNIQUE_SHAPE_HPP
#define UNIQUE_SHAPE_HPP
#include "shape.hpp"
#include "basic_shapes.hpp"
#include <vector>
#include <memory>
class Hamburger : public Shape {
private:
    double cheeseHeight = 10;
    double pattyHeight = 25;
    double lettuceHeight = 20;
    double bunHeight = 30;
    int _numPatties;
    int _numLettuce;
    int _numCheese;
    enum HamburgerFillings { patty = 1, cheese = 2, lettuce = 3 };

    std::vector<std::vector<Rectangle>> _fillings;


public:
  Hamburger(const int &patties, const int &cheese, const int &lettuce);
  void draw(std::ostream &file) const;
};
#endif