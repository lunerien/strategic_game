//
// Created by lukasz.kala on 14.07.2023.
//

#include <iostream>
#include "../app/units/WarUnit.h"
#include "CppUTest/TestHarness.h"
#include "../app/units/UnitFactory.h"

TEST_GROUP(UnitTestsGroup) {
    void setup() {
        map = new Map({
                              {'0', '0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0', '0'}
                      });

        unitFactory = new UnitFactory(Owner{Owner::OwnerType::Player}, Owner{Owner::OwnerType::Enemy},
                                      UnitFactory::FactoryState::Idle, *map);

        warUnit = dynamic_cast<WarUnit *>(unitFactory->createUnit(UnitType::Type::Knight,
                                                                  Owner{Owner::OwnerType::Player},
                                                                  Coordinates{0, 0}, Coordinates{5, 5},
                                                                  Coordinates{5, 5}, 0,
                                                                  Unit::UnitState::Standing));
    }

    void teardown() {
        delete map;
        delete unitFactory;
    }

    UnitFactory *unitFactory;
    WarUnit *warUnit;
    Map *map;
};


TEST(UnitTestsGroup, dumpLoadTest) {
    CHECK(warUnit);
    std::string dump = warUnit->dumpObject();
    Unit *loadedUnit = unitFactory->createUnit(dump);
    CHECK_EQUAL(dump, loadedUnit->dumpObject());
};