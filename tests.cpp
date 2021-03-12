#include "headers/catch.hpp"
#include "headers/shape.hpp"
#include "headers/basic_shapes.hpp"
#include <fstream>
#include <math.h>

std::string readFile()
{
    std::string buildOutput;
    std::string line;
    std::ifstream test_file("build_test.ps");
    while (getline(test_file, line))
    {
        buildOutput += line;
        buildOutput += "\n";
    }
    return buildOutput;
}
TEST_CASE("Draw a circle.")
{
    std::ofstream ofs;
    ofs.open("build_test.ps");
    Circle circle(144);
    circle.draw(ofs);
    ofs.close();
    REQUIRE(readFile() == "newpath\n144 144 144 0 360 arc \nstroke\n");
}
TEST_CASE("Make sure a polygon has the correct size sides")
{
    Polygon polygon1(4, 4.0);

    REQUIRE(abs(polygon1.getHeight() - 4.0 < 0.01));
    REQUIRE(abs(polygon1.getWidth() - 4.0 < 0.01));
}

TEST_CASE("Draw a rectangle")
{
    std::ofstream ofs;
    ofs.open("build_test.ps");
    Rectangle rectangle(50, 100);
    rectangle.draw(ofs);
    ofs.close();
    REQUIRE(readFile() == "newpath\n25 50 50 100 rectstroke \nstroke\n");
}

TEST_CASE("Draw a polygon.")
{
    std::ofstream ofs;
    ofs.open("build_test.ps");
    Polygon polygon(4, 100);
    polygon.draw(ofs);
    ofs.close();

    REQUIRE(readFile() == "Correct output goes here");
}