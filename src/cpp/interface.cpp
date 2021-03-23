#include "../headers/interface.hpp"
void setCursor(std::ostream &file, double x, double y) {
  file << x << " " << y << " translate\n";
}
std::shared_ptr<Polygon> makePolygon(const int &numSides, const double &sideLength) {
    return std::make_shared<Polygon>(numSides, sideLength);
}
std::shared_ptr<Circle> makeCircle(double radius) {
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