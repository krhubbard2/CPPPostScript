#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <fstream>
// Base Class

class Shape
{
private:
    double _height = 0;
    double _width = 0;

public:
    double getHeight() const;
    double getWidth() const;
    void setHeight(const double &height);
    void setWidth(const double &width);
    virtual void draw(std::ofstream &file) const = 0;
    virtual ~Shape() = default;
};

#endif