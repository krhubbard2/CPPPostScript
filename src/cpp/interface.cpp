#include "../headers/interface.hpp"
void setCursor(std::ostream &file, const double &x, const double &y) {
  file << x << " " << y << " translate\n";
}
std::shared_ptr<Polygon> makePolygon(const int &numSides, const double &sideLength) {
    return std::make_shared<Polygon>(numSides, sideLength);
}
std::shared_ptr<Circle> makeCircle(const double &radius) {
  return std::make_shared<Circle>(radius);
}
std::shared_ptr<Triangle> makeTriangle(const double &sideLength) {
    return std::make_shared<Triangle>(sideLength);
}
std::shared_ptr<Rectangle> makeRectangle(const double &width, const double &height) {
    return std::make_shared<Rectangle>(width, height);
}
std::shared_ptr<Spacer> makeSpacer(const double &width, const double &height) {
    return std::make_shared<Spacer>(width, height);
}
std::shared_ptr<Square> makeSquare(const double &sideLength) {
    return std::make_shared<Square>(sideLength);
}
std::shared_ptr<Scaled> makeScaled(std::shared_ptr<Shape> shape, const double &fx, const double &fy) {
    return std::make_shared<Scaled>(shape, fx, fy);
}
std::shared_ptr<Rotated> makeRotated(std::shared_ptr<Shape> shape, const Rotated::RotationAngle &angle) {
    return std::make_shared<Rotated>(shape, angle);
}
std::shared_ptr<Layered> makeLayered(const std::vector<std::shared_ptr<Shape>> &shapes) {
    return std::make_shared<Layered>(shapes);
}
std::shared_ptr<Horizontal> makeHorizontal(const std::vector<std::shared_ptr<Shape>> &shapes) {
    return std::make_shared<Horizontal>(shapes);
}
std::shared_ptr<Vertical> makeVertical(const std::vector<std::shared_ptr<Shape>> &shapes) {
    return std::make_shared<Vertical>(shapes);
}

std::shared_ptr<Hamburger> makeHamburger(const int &patties, const int &cheese, const int &lettuce) {
    return std::make_shared<Hamburger>(patties,cheese,lettuce);
}