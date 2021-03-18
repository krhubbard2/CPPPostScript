#include "../headers/complex_shapes.hpp"
#include <sstream>
using std::stringstream;

void Rotated::draw(std::ostream &file) const {
  stringstream output;
  output << "gsave\n" << _shape->getWidth()/2 << " " << _shape->getHeight()/2 << " translate\n"
         << _rotationAngle << " rotate\n" <<
          "-" << _shape->getWidth()/2 << " -" << _shape->getHeight()/2 << " translate\n";
          _shape->draw(output);
          output << "\ngrestore";
  file << output.rdbuf();
}