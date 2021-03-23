#include "../headers/basic_shapes.hpp"
#include <sstream>
#include <string>
#define M_PI 3.14159265358979323846
#include <cmath>

using std::string;
using std::stringstream;

Circle::Circle(const double &radius) : _radius(radius) {
  setHeight(radius * 2);
  setWidth(radius * 2);
}

void Circle::draw(std::ostream &file) const {
  stringstream output;

  output << "gsave\nnewpath\n"
         << "0 0 " << _radius << " 0 360 arc \nstroke\ngrestore\n";
  file << output.rdbuf();
}

Polygon::Polygon(const int &numberSides, const double &sideLength)
    : _numSides(numberSides), _sideLength(sideLength) {
  if (numberSides % 2 == 1) {
    double height = (sideLength * (1 + cos(M_PI / numberSides)) /
                     (2 * sin(M_PI / numberSides)));
    setHeight(height);
    double width =
        (sideLength * sin((M_PI * (numberSides - 1)) / (2 * numberSides)) /
         (sin(M_PI / numberSides)));
    setWidth(width);

  } else if (numberSides % 4 == 0) {
    double height =
        (sideLength * (cos(M_PI / numberSides)) / (sin(M_PI / numberSides)));
    setHeight(height);
    double width =
        (sideLength * cos(M_PI / numberSides)) / (sin(M_PI / numberSides));
    setWidth(width);

  } else {
    double height =
        (sideLength * (cos(M_PI / numberSides)) / (sin(M_PI / numberSides)));
    setHeight(height);
    double width = (sideLength / (sin(M_PI / numberSides)));
    setWidth(width);
  }
}

void Polygon::draw(std::ostream &file) const {
  stringstream output;
  output << "gsave\n"
         << "/u " << _sideLength
         << " def % unit: 0.5 inch\n/lw 1 u div def \n/n " << _numSides
         << " def\n/da 360 n div def % angle increment\n/a 90 def"
         << "\nu dup scale\nlw setlinewidth \nnewpath\n0 1 moveto\nn 1 sub {/a a da add def % increase angle\n  "
            "a cos a sin lineto % draw line\n} repeat\nclosepath\nstroke\ngrestore\n";
  file << output.rdbuf();
}

Rectangle::Rectangle(const double &width, const double &height) {
  setWidth(width);
  setHeight(height);
}

void Rectangle::draw(std::ostream &file) const {
  stringstream output;

  output << "gsave\nnewpath\n"
         << "-" << getWidth() / 2.0 << " -" << getHeight() / 2.0 << " "
         << getWidth() << " " << getHeight()
         << " rectstroke \nstroke\ngrestore\n";
  file << output.rdbuf();
}

void Spacer::draw(std::ostream &file) const {
  stringstream output;
  output << "";
  file << output.rdbuf();
}