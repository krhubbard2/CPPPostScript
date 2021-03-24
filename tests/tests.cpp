#include "../src/headers/basic_shapes.hpp"
#include "../src/headers/complex_shapes.hpp"
#include "../src/headers/interface.hpp"
#include "../src/headers/shape.hpp"
#include "../src/headers/unique_shapes.hpp"
#include <catch2/catch.hpp>
#include <fstream>
#include <initializer_list>
#include <math.h>
#include <sstream>

// *********************************************************************
// Simple Shapes Tests
// *********************************************************************

TEST_CASE("Draw a circle.") {
  std::ostringstream output;
  // Circle circle(144);
  auto circle = makeCircle(144);
  circle->draw(output);

  REQUIRE(output.str() ==
          "gsave\nnewpath\n0 0 144 0 360 arc \nstroke\ngrestore\n");
}
TEST_CASE("Make sure a polygon has the correct size sides") {
  auto polygon = makePolygon(4, 4.0);

  REQUIRE(polygon->getHeight() - 4.0 < 0.01);
  REQUIRE(polygon->getWidth() - 4.0 < 0.01);
}

TEST_CASE("Draw a rectangle") {
  std::ostringstream output;
  auto rectangle = makeRectangle(50,100);
  rectangle->draw(output);

  REQUIRE(output.str() ==
          "gsave\nnewpath\n-25 -50 50 100 rectstroke \nstroke\ngrestore\n");
}

TEST_CASE("Draw a polygon.") {
  std::ostringstream output;
  auto polygon = makePolygon(4,100);
  polygon->draw(output);

  REQUIRE(output.str() ==
          "gsave\n/u 100 def \n/lw 1 u div def \n/n 4 def\n/da 360 n div def "
          "\n/a 90 def\nu dup scale\nlw setlinewidth \nnewpath\n0 1 moveto\nn "
          "1 sub {/a a da add def \n  a cos a sin lineto \n} "
          "repeat\nclosepath\nstroke\ngrestore\n");
}

TEST_CASE("Draw a triangle.") {
  std::ostringstream output;
  auto triangle = makeTriangle(100);
  triangle->draw(output);

  REQUIRE(output.str() ==
          "gsave\n/u 100 def \n/lw 1 u div def \n/n 3 def\n/da 360 n div def "
          "\n/a 90 def\nu dup scale\nlw setlinewidth \nnewpath\n0 1 moveto\nn "
          "1 sub {/a a da add def \n  a cos a sin lineto \n} "
          "repeat\nclosepath\nstroke\ngrestore\n");
}

TEST_CASE("Draw a Square.") {
  std::ostringstream output;
  auto square = makeSquare(100);
  square->draw(output);

  REQUIRE(output.str() ==
          "gsave\n/u 100 def \n/lw 1 u div def \n/n 4 def\n/da 360 n div def "
          "\n/a 90 def\nu dup scale\nlw setlinewidth \nnewpath\n0 1 moveto\nn "
          "1 sub {/a a da add def \n  a cos a sin lineto \n} "
          "repeat\nclosepath\nstroke\ngrestore\n");
}

// *********************************************************************
// Complex Shapes Tests
// *********************************************************************

TEST_CASE("Rotate a Triangle") {
  auto triangle = makeTriangle(50);
  auto rotated = makeRotated(triangle,Rotated::ninety);
  std::ostringstream output;
  rotated->draw(output);
  REQUIRE(output.str() ==
          "gsave\n25 21.6506 translate\n90 rotate\n-25 -21.6506 "
          "translate\ngsave\n/u 50 def \n/lw 1 u div def \n/n 3 def\n/da 360 n "
          "div def \n/a 90 def\nu dup scale\nlw setlinewidth \nnewpath\n0 1 "
          "moveto\nn 1 sub {/a a da add def \n  a cos a sin lineto \n} "
          "repeat\nclosepath\nstroke\ngrestore\n\ngrestore");
}

TEST_CASE("Scale a Triangle") {
  auto triangle = makeTriangle(50);
  auto scaled = makeScaled(triangle, 5, 5);
  std::ostringstream output;
  scaled->draw(output);
  REQUIRE(output.str() ==
          "gsave\n5 5 scale\ngsave\n/u 50 def \n/lw 1 u div def \n/n 3 "
          "def\n/da 360 n div def \n/a 90 def\nu dup scale\nlw setlinewidth "
          "\nnewpath\n0 1 moveto\nn 1 sub {/a a da add def \n  a cos a sin "
          "lineto \n} repeat\nclosepath\nstroke\ngrestore\ngrestore");
}

TEST_CASE("Layered Shapes") {
  auto triangle = makeTriangle(50);
  auto rectangle = makeRectangle(100, 150);
  auto triangle2 = makeTriangle(100);

  std::vector<std::shared_ptr<Shape>> shapes = {triangle, rectangle, triangle2};
  auto layered = makeLayered(shapes);
  std::ostringstream output;
  setCursor(output, 200.0, 200.0);
  layered->draw(output);
  REQUIRE("\n200 200 translate\ngsave\n/u 50 def \n/lw 1 u div def \n/n 3 def\n/da 360 n div def \n/a 90 def\nu dup scale\nlw setlinewidth \nnewpath\n0 1 moveto\nn 1 sub {/a a da add def \na cos a sin lineto \n} repeat\nclosepath\nstroke\ngrestore\ngsave\nnewpath\n-50 -75 100 150 rectstroke \nstroke\ngrestore\ngsave\n/u 100 def \n/lw 1 u div def \n/n 3 def\n/da 360 n div def \n/a 90 def\nu dup scale\nlw setlinewidth \nnewpath\n0 1 moveto\nn 1 sub {/a a da add def \na cos a sin lineto \n} repeat\nclosepath\nstroke\ngrestore");
}

TEST_CASE("Horizontal Drawing") {
  auto rectangle = makeRectangle(30, 150);
  auto circle = makeCircle(50);
  auto triangle = makeTriangle(60);

  std::vector<std::shared_ptr<Shape>> shapes = {rectangle, circle, triangle};
  auto horizontal = makeHorizontal(shapes);
  std::ostringstream output;
  setCursor(output, 200.0, 200.0);
  horizontal->draw(output);
  REQUIRE(
      output.str() ==
      "\n200 200 translate\n15 0 translate\ngsave\nnewpath\n-15 -75 30 150 "
      "rectstroke \nstroke\ngrestore\n15 0 translate\n50 0 "
      "translate\ngsave\nnewpath\n0 0 50 0 360 arc \nstroke\ngrestore\n50 0 "
      "translate\n30 0 translate\ngsave\n/u 60 def \n/lw 1 u div def \n/n 3 "
      "def\n/da 360 n div def \n/a 90 def\nu dup scale\nlw setlinewidth "
      "\nnewpath\n0 1 moveto\nn 1 sub {/a a da add def \n  a cos a sin lineto "
      "\n} repeat\nclosepath\nstroke\ngrestore\n30 0 translate\n");
}

TEST_CASE("Vertical Drawing") {
  auto circle = makeCircle(45);
  auto triangle = makeTriangle(60);
  auto square = makeSquare(60);
  auto rectangle = makeRectangle(100, 50);
  auto circle2 = makeCircle(50);

  std::vector<std::shared_ptr<Shape>> shapes = {circle, triangle, square,
                                                rectangle, circle2};
  auto vertical = makeVertical(shapes);
  std::ostringstream output;
  setCursor(output, 200.0, 200.0);
  vertical->draw(output);
  REQUIRE(
      output.str() ==
      "\n200 200 translate\n0 45 translate\ngsave\nnewpath\n0 0 45 0 360 "
      "arc \nstroke\ngrestore\n0 45 translate\n0 25.9808 translate\ngsave\n/u"
      " 60 def \n/lw 1 u div def \n/n 3 def\n/da 360 n div def \n/a 90 def\nu "
      "dup scale\nlw setlinewidth \nnewpath\n0 1 moveto\nn 1 sub {/a a da "
      "add def \n  a cos a sin lineto \n}"
      " repeat\nclosepath\nstroke\ngrestore\n0 25.9808 translate\n0 30 "
      "translate\ngsave\n/u 60 def \n/lw 1 u div def \n/n 4 def\n/da 360 n "
      "div def \n/a 90 def\nu dup scale\nlw setlinewidth \nnewpath\n0 1 "
      "moveto\nn 1 sub {/a a da add def \n  a cos a sin lineto \n} "
      "repeat\nclosepath\nstroke\ngrestore\n0 30 translate\n0 25 "
      "translate\ngsave\nnewpath\n-50 -25 100 50 "
      "rectstroke \nstroke\ngrestore\n0 25 translate\n0 50 "
      "translate\ngsave\nnewpath\n0 0 50 0 360 arc \nstroke\ngrestore\n0 50 "
      "translate\n");
}

TEST_CASE("Hamburger drawing") {
  auto hamburger = makeHamburger(2,1,1);
  std::ostringstream output;
  setCursor(output, 200.0, 200.0);
  hamburger->draw(output);
  REQUIRE(output.str() ==
          "\n200 200 translate\n1.0 0.7 0.0 setrgbcolor fill\n0 15 "
          "translate\ngsave\nnewpath\n-50 -15 100 30 "
          "rectstroke \nstroke\ngrestore\n0 15 translate\n0.7 0.3 0.0 "
          "setrgbcolor fill\n0 12.5 translate\ngsave\nnewpath\n-50 -12.5 100 "
          "25 rectstroke \nstroke\ngrestore\n0 12.5 translate\n0.7 0.3 0.0 "
          "setrgbcolor fill\n0 12.5 translate\ngsave\nnewpath\n-50 -12.5 100 "
          "25 rectstroke \nstroke\ngrestore\n0 12.5 translate\n1.0 1.0 0.0 "
          "setrgbcolor fill\n0 5 translate\ngsave\nnewpath\n-50 -5 100 10 "
          "rectstroke \nstroke\ngrestore\n0 5 translate\n0.0 1.0 0.0 "
          "setrgbcolor fill\n0 10 translate\ngsave\nnewpath\n-50 -10 100 20 "
          "rectstroke \nstroke\ngrestore\n0 10 translate\n1.0 0.7 0.0 "
          "setrgbcolor fill\n0 15 translate\ngsave\nnewpath\n-50 -15 100 30 "
          "rectstroke \nstroke\ngrestore\n0 15 translate\n");
}