#include "headers/catch.hpp"
#include "headers/shape.hpp"
#include "headers/basic_shapes.hpp"
#include <fstream>

TEST_CASE( "Draw a circle." ){
    std::ofstream ofs;
    ofs.open("build_test.ps");
    Circle circle(144);
    circle.draw(ofs);
    REQUIRE(1 == 1);
}