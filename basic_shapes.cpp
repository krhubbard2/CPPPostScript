#include "headers/basic_shapes.hpp"
#include <string>
#include <sstream>
#include <cmath>

using std::string;
using std::stringstream;

Circle::Circle(const double &radius) : _radius(radius)
{
    setHeight(radius * 2);
    setWidth(radius * 2);
}

void Circle::draw(std::ofstream &file) const
{
    stringstream output;

    output << "newpath\n"
           << getHeight() / 2.0 << " " << getWidth() / 2.0 << " " << _radius << " 0 360 arc \nstroke\n";
    file << output.rdbuf();
}

Polygon::Polygon(const int &numberSides, const double &sideLength) : _numSides(numberSides), _sideLength(sideLength)
{
    if (numberSides % 2 == 1)
    {
        double height = sideLength * (1 + cos(M_PI / numberSides)) / (2 * sin(M_PI / numberSides));
        setHeight(height);
        double width = (sideLength * sin((M_PI * (numberSides - 1)) / (2 * numberSides)) / (sin(M_PI / numberSides)));
        setWidth(width);
    }
    else if (numberSides % 4 == 0)
    {
        double height = sideLength * (cos(M_PI / numberSides)) / (sin(M_PI / numberSides));
        setHeight(height);
        double width = (sideLength * cos(M_PI / numberSides)) / (sin(M_PI / numberSides));
        setWidth(width);
    }
    else
    {
        double height = sideLength * (cos(M_PI)) / (sin(M_PI / sideLength));
        setHeight(height);
        double width = sideLength / (sin(M_PI / sideLength));
        setWidth(width);
    }
}
void Polygon::draw(std::ofstream &file) const
{
    stringstream output;
    // Magic code -- This code below... draws a polygon?
    output << "newpath\n"
           << getWidth() / 2 << " " << getHeight() / 2 << " translate\n"
           << "/S " << _numSides << " def /H " << getHeight() / 2 << " \ndef"
           << " /A 360 S div def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } repeat\n"
           << "closepath\n stroke";

    file << output.rdbuf();
}

Rectangle::Rectangle(const double &width, const double &height)
{
    setWidth(width);
    setHeight(height);
}

void Rectangle::draw(std::ofstream &file) const
{
    stringstream output;

    output << "newpath\n"
           << getWidth() / 2.0 << " " << getHeight() / 2.0 << " " << getWidth() << " " << getHeight() << " rectstroke \nstroke\n";
    file << output.rdbuf();
}