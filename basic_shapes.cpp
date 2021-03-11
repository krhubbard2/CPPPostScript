#include "headers/basic_shapes.hpp"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Circle::Circle(const double & radius) {
    _radius = radius;
    setHeight(radius*2);
    setWidth(radius*2);
}

void Circle::draw(std::ofstream &file) const
{
    stringstream output;


    output << "newpath\n" << getHeight()/2.0 << " " << getWidth()/2.0 << " " << _radius << " 0 360 arc \nstroke\n";
    file << output.rdbuf();
}