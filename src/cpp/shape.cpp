#include "../headers/shape.hpp"


double Shape::getHeight() const{
    return _height;
}

double Shape::getWidth() const{
    return _width;
}

void Shape::setHeight(const double & height){
    _height = height;
}

void Shape::setWidth(const double & width){
    _width = width;
}

