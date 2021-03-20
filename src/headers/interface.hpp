#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <fstream>
#include <iostream>

void setCursor(std::ostream &file, double x, double y) {
  file << x << " " << y << " translate\n";
}
#endif