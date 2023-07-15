//
// Created by lukasz.kala on 14.07.2023.
//

#include "CppUTest/TestHarness.h"
#include "../app/units/WarUnit.h"


TEST_GROUP(UnitTestsGroup) {
    void setup() {
        map = new Map({
                              {'0','0','0','0','0','0','0'},
                              {'0','0','0','0','0','0','0'},
                              {'0','0','0','0','0','0','0'},
                              {'0','0','0','0','0','0','0'},
                              {'0','0','0','0','0','0','0'},
                              {'0','0','0','0','0','0','0'},
                              {'0','0','0','0','0','0','0'}
                      });
        warUnit = new WarUnit(
                {Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                Coordinates{0, 0}, *map}, WarUnit::MeleState::ProtectingBase
        );
    }

    void teardown() {
        delete map;
        delete warUnit;
    }

    WarUnit *warUnit;
    Map* map;
};


TEST(UnitTestsGroup, dumpLoadTest) {

};