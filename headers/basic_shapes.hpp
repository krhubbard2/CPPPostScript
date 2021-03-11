#ifndef BASIC_SHAPES_HPP
#define BASIC_SHAPES_HPP

#include "shape.hpp"
#include <fstream>

class Circle : public Shape{
    private:
        double _radius;
    public:
        Circle(const double &radius);
        void draw(std::ofstream &file) const;
};

class Polygon : public Shape{
    private:
        int _numSides;
        double sideLength;
    public:
        Polygon(const int & numberSides, const double & sideLength);
        void draw(std::ofstream &file) const;
};

// class Rectangle : public Shape{
//     private:
//         double _width;
//         double _height;
//     public:
// };

// class Spacer : public Shape{
//     private:
//     public:
// };

// class Square : public Shape{
//     private:
//     public:
// };

// class Triangle : public Shape{
//     private:
//     public:
// };

#endif