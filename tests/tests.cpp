#include "../src/headers/basic_shapes.hpp"
#include "../src/headers/complex_shapes.hpp"
#include "../src/headers/shape.hpp"
#include <catch2/catch.hpp>
#include <fstream>
#include <math.h>
#include <sstream>
#include <initializer_list>

TEST_CASE("Draw a circle.") {
  std::ostringstream output;
  Circle circle(144);
  circle.draw(output);

  REQUIRE(output.str() ==
          "gsave\nnewpath\n144 144 144 0 360 arc \nstroke\ngrestore\n");
}
TEST_CASE("Make sure a polygon has the correct size sides") {
  Polygon polygon1(4, 4.0);

  REQUIRE(polygon1.getHeight() - 4.0 < 0.01);
  REQUIRE(polygon1.getWidth() - 4.0 < 0.01);
}

TEST_CASE("Draw a rectangle") {
  std::ostringstream output;
  Rectangle rectangle(50, 100);
  rectangle.draw(output);

  REQUIRE(output.str() ==
          "gsave\nnewpath\n25 50 50 100 rectstroke \nstroke\ngrestore\n");
}

TEST_CASE("Draw a polygon.") {
  std::ostringstream output;
  Polygon polygon(4, 100);
  polygon.draw(output);

  REQUIRE(output.str() ==
          "gsave\nnewpath\n50 50 translate\n/S 4 def /H 50 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\n");
}

TEST_CASE("Draw a triangle.") {
  std::ostringstream output;
  Triangle triangle(100);
  triangle.draw(output);

  REQUIRE(output.str() ==
          "gsave\nnewpath\n50 43.3013 translate\n/S 3 def /H 43.3013 \ndef /A "
          "360 S div def A cos H mul H sub A sin H mul 0 sub atan rotate -90 "
          "rotate H 0 moveto S{ A cos H mul A sin H mul lineto /A A 360 S div "
          "add def } repeat\nclosepath\nstroke\ngrestore\n");
}

TEST_CASE("Draw a Square.") {
  std::ostringstream output;
  Square square(100);
  square.draw(output);

  REQUIRE(output.str() ==
          "gsave\nnewpath\n50 50 translate\n/S 4 def /H 50 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\n");
}

TEST_CASE("Rotate a Triangle") {
  auto triangle = std::make_unique<Triangle>(50);

  Rotated rotated(std::move(triangle), Rotated::ninety);
  std::ostringstream output;
  rotated.draw(output);
  REQUIRE(output.str() ==
      "gsave\n25 21.6506 translate\n90 rotate\n-25 -21.6506 "
      "translate\ngsave\nnewpath\n25 21.6506 translate\n/S 3 def /H 21.6506 "
      "\ndef /A 360 S div def A cos H mul H sub A sin H mul 0 sub atan rotate "
      "-90 rotate H 0 moveto S{ A cos H mul A sin H mul lineto /A A 360 S div "
      "add def } repeat\nclosepath\nstroke\ngrestore\n\ngrestore");
}

TEST_CASE("Scale a Triangle"){
  auto triangle = std::make_unique<Triangle>(50);

  Scaled scaled(std::move(triangle), 5, 5);
  std::ostringstream output;
  scaled.draw(output);
  REQUIRE(output.str() ==
      "gsave\n5 5 scale\n"
      "gsave\nnewpath\n25 21.6506 translate\n/S 3 def /H 21.6506 "
      "\ndef /A 360 S div def A cos H mul H sub A sin H mul 0 sub atan rotate "
      "-90 rotate H 0 moveto S{ A cos H mul A sin H mul lineto /A A 360 S div "
      "add def } repeat\nclosepath\nstroke\ngrestore\n\ngrestore");
}

TEST_CASE("Layered Shapes") {
  auto triangle = std::make_shared<Triangle>(50);
  auto square = std::make_shared<Square>(100);
  
  std::vector<std::shared_ptr<Shape>> shapes = {triangle,square}; 
  Layered layered(shapes);
  std::ostringstream output;
  layered.draw(output);
}