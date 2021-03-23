#include "../headers/unique_shapes.hpp"
#include <sstream>
using std::stringstream;
Hamburger::Hamburger(const int &patties, const int &cheese, const int &lettuce):_numCheese(cheese),_numLettuce(lettuce),_numPatties(patties) {
    setHeight( (patties * pattyHeight) + (cheese * cheeseHeight) + (lettuce * lettuceHeight) + (2 * bunHeight));
    setWidth(200);
}

void Hamburger::draw(std::ostream &file) const{
  stringstream output;
  auto cheeseRectangle = std::make_shared<Rectangle>(100,cheeseHeight);
  auto pattyRectangle = std::make_shared<Rectangle>(100,pattyHeight);
  auto lettuceRectangle = std::make_shared<Rectangle>(100,lettuceHeight);
  auto bunRectangle = std::make_shared<Rectangle>(100,bunHeight);

  output << "1.0 0.7 0.0 setrgbcolor fill\n";
  output << "0 " << bunRectangle->getHeight()/2 << " translate\n";
  bunRectangle->draw(output);
  output << "0 " << bunRectangle->getHeight()/2 << " translate\n";

  for (int i = 0; i < _numPatties;i++) {
    output << "0.7 0.3 0.0 setrgbcolor fill\n";
    output << "0 " << pattyRectangle->getHeight()/2 << " translate\n";
    pattyRectangle->draw(output);
    output << "0 " << pattyRectangle->getHeight()/2 << " translate\n";

  }

  for (int i = 0; i < _numCheese;i++) {
    output << "1.0 1.0 0.0 setrgbcolor fill\n";
    output << "0 " << cheeseRectangle->getHeight()/2 << " translate\n";
    cheeseRectangle->draw(output);
    output << "0 " << cheeseRectangle->getHeight()/2 << " translate\n";

  }

  for (int i = 0; i < _numLettuce;i++) {
    output << "0.0 1.0 0.0 setrgbcolor fill\n";
    output << "0 " << lettuceRectangle->getHeight()/2 << " translate\n";
    lettuceRectangle->draw(output);
    output << "0 " << lettuceRectangle->getHeight()/2 << " translate\n";

  }

  output << "1.0 0.7 0.0 setrgbcolor fill\n";
  output << "0 " << bunRectangle->getHeight()/2 << " translate\n";
  bunRectangle->draw(output);
  output << "0 " << bunRectangle->getHeight()/2 << " translate\n";


  file << output.str();
}

