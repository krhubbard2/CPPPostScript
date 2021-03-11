#include "headers/catch.hpp"
#include "headers/shape.hpp"
#include "headers/basic_shapes.hpp"
#include <fstream>

TEST_CASE( "Draw a circle." ){
    std::ofstream ofs;
    ofs.open("build_test.ps");
    Circle circle(144);
    circle.draw(ofs);
    

/*
Circle circle(72)
Sqaure square(72)
Horizontal h(circle,square)
h.draw()
*/

    REQUIRE(1 == 1);
}