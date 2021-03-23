cmake_minimum_required(VERSION 3.0.0)
project(CPS VERSION 0.1.0)

include(CTest)
enable_testing()
set (CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)
add_executable(test_suite tests/catch_main.cpp tests/tests.cpp src/cpp/shape.cpp src/cpp/basic_shapes.cpp src/cpp/complex_shapes.cpp src/cpp/interface.cpp)
target_link_libraries(test_suite PRIVATE Catch2::Catch2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
