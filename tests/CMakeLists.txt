cmake_minimum_required(VERSION 3.26)
project(strategic_game_tests)

add_executable(strategic_game_tests testMain.cpp
        exampleTest.cpp)
target_compile_options(strategic_game_tests PUBLIC -Werror -Wall -Wextra -Wpedantic)
target_link_libraries(strategic_game_tests PRIVATE CppUTest)