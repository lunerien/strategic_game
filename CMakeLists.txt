cmake_minimum_required(VERSION 3.25.2)
project(strategic_game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(strategic_game
        main.cpp
        app/Map.cpp
        app/units/WarUnit.cpp
        app/utils/Chance.cpp
        app/units/WorkerUnit.cpp
        app/units/UnitFactory.cpp
        app/utils/Range.cpp
        app/units/BaseUnit.cpp
        )

target_compile_options(strategic_game PUBLIC -Werror -Wall -Wextra -Wpedantic)
set(TESTS_BUILD_DISCOVER OFF CACHE BOOL "CppUTest Switch off Build time test discover" FORCE)
set(TESTS OFF CACHE BOOL "CppUTest Switch off CppUTest Test build" FORCE)
set(EXTENSIONS OFF CACHE BOOL "CppUTest Switch off compiling extensions" FORCE)
set(C++11 ON CACHE BOOL "CppUTest Switch on C++11" FORCE)
set(VERBOSE_CONFIG OFF CACHE BOOL "CppUTest Turn off print configuration to stdout during generation" FORCE)
set(CPPUTEST_FLAGS OFF CACHE BOOL "CppUTest Dont use the CFLAGS/CXXFLAGS/LDFLAGS set by CppUTest" FORCE)
set(TESTS_DETAILED ON CACHE BOOL "CppUTest Run tests separately" FORCE)
add_subdirectory(lib/cpputest)
add_subdirectory(tests)