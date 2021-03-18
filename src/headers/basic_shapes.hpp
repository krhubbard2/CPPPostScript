#ifndef BASIC_SHAPES_HPP
#define BASIC_SHAPES_HPP

#include "shape.hpp"
#include <fstream>

class Circle : public Shape
{
private:
    double _radius;

public:
    Circle(const double &radius);
    void draw(std::ostream &file) const;
};

class Polygon : public Shape
{
private:
    int _numSides;
    double _sideLength;

public:
    Polygon(const int &numberSides, const double &sideLength);
    void draw(std::ostream &file) const;
};

class Rectangle : public Shape
{
private:
    double _width;
    double _height;

public:
    Rectangle(const double &width, const double &height);
    void draw(std::ostream &file) const;
};

class Spacer : public Shape{
    private:
        double _width;
        double _height;
    public:
        Spacer(const double &width, const double &height) : _width(width),_height(height){};
        void draw(std::ostream &file) const;
};

class Square : public Polygon{
    public:
        Square(const double & length): Polygon(4,length){}
};

class Triangle : public Polygon{
    public:
        Triangle(const double & length): Polygon(3, length){}
};

#endif