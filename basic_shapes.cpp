#include "headers/basic_shapes.hpp"
#include <string>
#include <sstream>
#include <cmath>   

using std::string;
using std::stringstream;

Circle::Circle(const double & radius) : _radius(radius) {
    setHeight(radius*2);
    setWidth(radius*2);
}

void Circle::draw(std::ofstream &file) const
{
    stringstream output;


    output << "newpath\n" << getHeight()/2.0 << " " << getWidth()/2.0 << " " << _radius << " 0 360 arc \nstroke\n";
    file << output.rdbuf();
}

Polygon::Polygon(const int & numberSides, const double & sideLength) {
    if(numberSides%2 == 1){
        //odd CASE_1
        double height = sideLength*(1+cos(M_PI/numberSides))/(2*sin(M_PI/numberSides));
        setHeight(height);
        double width = (sideLength*sin((M_PI*(numberSides-1))/(2*numberSides))/(sin(M_PI/numberSides)));
    }
    else if(numberSides % 4 == 0){
        double height = sideLength*(cos(M_PI/numberSides))/(sin(M_PI/numberSides));
        setHeight(height);
        double width = (sideLength*cos(M_PI/numberSides))/(sin(M_PI/numberSides));
        setWidth(width);
    }
    else{
        double height = sideLength*(cos(M_PI));
    }
}
