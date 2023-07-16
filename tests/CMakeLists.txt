cmake_minimum_required(VERSION 3.22.1)
project(strategic_game_tests)


add_executable(rangeTests
        testMain.cpp
        rangeTests.cpp
        ../app/utils/Range.cpp
        ../app/Map.cpp
        ../app/units/WarUnit.cpp
        ../app/units/BaseUnit.cpp
        ../app/units/UnitFactory.cpp
        ../app/units/WorkerUnit.cpp
        ../app/units/BaseBuildingUnit.cpp)
target_compile_options(rangeTests PUBLIC -Werror -Wall -Wextra -Wpedantic)
target_link_libraries(rangeTests PRIVATE CppUTest)

add_executable(unitTests
        testMain.cpp
        unitTests.cpp
        ../app/utils/Range.cpp
        ../app/Map.cpp
        ../app/units/WarUnit.cpp
        ../app/units/BaseUnit.cpp
        ../app/units/UnitFactory.cpp
        ../app/units/WorkerUnit.cpp
        ../app/units/BaseBuildingUnit.cpp
        unitTests.cpp)
target_compile_options(unitTests PUBLIC -Werror -Wall -Wextra -Wpedantic)
target_link_libraries(unitTests PRIVATE CppUTest)

add_test(NAME rangeTests COMMAND rangeTests)
add_test(NAME unitTests COMMAND unitTests)