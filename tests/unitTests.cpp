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

        unitFactoryForLoading = new UnitFactory(Owner{Owner::OwnerType::Player}, Owner{Owner::OwnerType::Enemy},
                                      UnitFactory::FactoryState::Idle, *map);

        warUnit = dynamic_cast<WarUnit *>(unitFactory->createUnit(UnitType::Type::Knight,
                                                                  Owner{Owner::OwnerType::Player},
                                                                  Coordinates{0, 0}, Coordinates{5, 5},
                                                                  Coordinates{5, 5}, 0,
                                                                  Unit::UnitState::Standing));

        workerUnit = dynamic_cast<WorkerUnit *>(unitFactory->createUnit(UnitType::Type::Worker,
                                                                        Owner{Owner::OwnerType::Player},
                                                                        Coordinates{0, 0}, Coordinates{5, 5},
                                                                        Coordinates{5, 5}, 0,
                                                                        Unit::UnitState::Standing));

        baseUnit = dynamic_cast<BaseUnit *>(unitFactory->createBase(Owner{Owner::OwnerType::Player},
                                                                    Coordinates{0, 0}, Coordinates{0, 0},
                                                                    Coordinates{0, 0}, 0,
                                                                    Unit::UnitState::Standing, 0,
                                                                    UnitType::Type::Worker, Stamina{0}));
    }

    void teardown() {
        delete map;
        delete unitFactory;
        delete unitFactoryForLoading;
    }

    UnitFactory *unitFactory;
    UnitFactory *unitFactoryForLoading;
    WarUnit *warUnit;
    WorkerUnit *workerUnit;
    BaseUnit *baseUnit;
    Map *map;
};

TEST(UnitTestsGroup, correctIdAssignmentTest) {
    CHECK_EQUAL(0, warUnit->getId());
    CHECK_EQUAL(1, workerUnit->getId());
    CHECK_EQUAL(2, baseUnit->getId());
};


TEST(UnitTestsGroup, dumpWarUnitLoadTest) {
    CHECK(warUnit);
    std::string dump = warUnit->dumpObject();
    //Try to add unit with duplicated ID
    CHECK_THROWS(std::invalid_argument,unitFactory->createUnit(dump));
    Unit *loadedUnit = unitFactoryForLoading->createUnit(dump);
    //Check if loaded unit is not null - load should be successful
    CHECK(loadedUnit);
    CHECK_EQUAL(dump, loadedUnit->dumpObject());
};

TEST(UnitTestsGroup, dumpWorkersLoadTest) {
    CHECK(workerUnit);
    std::string dump = workerUnit->dumpObject();
    //Try to add unit with duplicated ID
    CHECK_THROWS(std::invalid_argument,unitFactory->createUnit(dump));
    Unit *loadedUnit = unitFactoryForLoading->createUnit(dump);
    //Check if loaded unit is not null - load should be successful
    CHECK(loadedUnit);
    CHECK_EQUAL(dump, loadedUnit->dumpObject());
};

TEST(UnitTestsGroup, dumpBaseLoadTest) {
    CHECK(baseUnit);
    std::string dump = baseUnit->dumpObject();
    //Try to add unit with duplicated ID
    CHECK_THROWS(std::invalid_argument,unitFactory->createUnit(dump));
    Unit *loadedUnit = unitFactoryForLoading->createUnit(dump);
    //Check if loaded unit is not null - load should be successful
    CHECK(loadedUnit);
    CHECK_EQUAL(dump, loadedUnit->dumpObject());
};

TEST(UnitTestsGroup, shoudntAllowToAddSecondBaseForPlayer)
{
    auto *baseUnit2 = dynamic_cast<BaseUnit *>(unitFactory->createBase(Owner{Owner::OwnerType::Player},
                                                                     Coordinates{0, 0}, Coordinates{0, 0},
                                                                     Coordinates{0, 0}, 0,
                                                                     Unit::UnitState::Standing, 0,
                                                                     UnitType::Type::Worker, Stamina{0}));
    CHECK_FALSE(baseUnit2);
}