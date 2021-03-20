#include "../headers/complex_shapes.hpp"
#include <sstream>
using std::stringstream;

void Rotated::draw(std::ostream &file) const {
  stringstream output;
  output << "gsave\n"
         << _shape->getWidth() / 2 << " " << _shape->getHeight() / 2
         << " translate\n"
         << _rotationAngle << " rotate\n"
         << "-" << _shape->getWidth() / 2 << " -" << _shape->getHeight() / 2
         << " translate\n";
  _shape->draw(output);
  output << "\ngrestore";
  file << output.rdbuf();
}

void Scaled::draw(std::ostream &file) const {
  stringstream output;
  output << "gsave\n" << _fx << " " << _fy << " scale\n";
  _shape->draw(output);
  output << "\ngrestore";
  file << output.rdbuf();
}

Layered::Layered(const std::vector<std::shared_ptr<Shape>> &shapes) {
  _shapes = shapes;
  for (const auto &shape : _shapes) {
    if (shape->getHeight() > getHeight()) {
      setHeight(shape->getHeight());
    }
    if (shape->getWidth() > getWidth()) {
      setWidth(getWidth());
    }
  }
};

void Layered::draw(std::ostream &file) const {
  for (const auto &shape : _shapes) {
    shape->draw(file);
  }
}

Vertical::Vertical(const std::vector<std::shared_ptr<Shape>> &shapes) {
  _shapes = shapes;
  for (const auto &shape : _shapes) {
    setHeight(getHeight() + shape->getHeight());
    if (shape->getWidth() > getWidth()) {
      setWidth(shape->getWidth());
    }
  }
};

void Vertical::draw(std::ostream &file) const {
  stringstream output;
  for (const auto &shape : _shapes) {
    output << "0 " << shape->getHeight()/2 << " translate\n";
    shape->draw(output);
    output << "0 " << shape->getHeight()/2 << " translate\n";
  }
  file << output.str();
}

Horizontal::Horizontal(const std::vector<std::shared_ptr<Shape>> &shapes) {
  _shapes = shapes;
  for (const auto &shape : _shapes) {
    setWidth(getWidth() + shape->getWidth());
    if (shape->getHeight() > getHeight()) {
      setHeight(shape->getHeight());
    }
  }
};

void Horizontal::draw(std::ostream &file) const {
  stringstream output;
  for (const auto &shape : _shapes) {
    output << shape->getWidth()/2 << " 0 translate\n";
    shape->draw(output);
    output << shape->getWidth()/2 << " 0 "
           << "translate\n";
  }
  file << output.str();
}