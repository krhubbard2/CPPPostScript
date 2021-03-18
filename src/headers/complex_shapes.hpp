#ifndef COMPLEX_SHAPES_HPP
#define COMPLEX_SHAPES_HPP

#include "shape.hpp"
#include <fstream>

class Rotated : public Shape
{
private:
    double _radius;

public:
    Rotated(Shape &shape, double rotationAngle);
    void draw(std::ofstream &file) const;
};
#endif