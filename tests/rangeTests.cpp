//
// Created by lukasz on 09.07.23.
//

#include "../app/utils/Range.h"
#include "CppUTest/TestHarness.h"
#include "../app/units/WorkerUnit.h"
#include "../app/units/UnitFactory.h"

TEST_GROUP(RangeTestsGroup) {
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
        goldStash = new GoldStash();
        unitFactory = new UnitFactory(Owner{Owner::OwnerType::Player}, Owner{Owner::OwnerType::Enemy}, *map, *goldStash);
    }

    void teardown() {
        delete map;
        delete unitFactory;
        delete goldStash;
    }
    UnitFactory *unitFactory;
    Map *map;
    GoldStash *goldStash;
};


TEST(RangeTestsGroup, moveTest) {
    auto targetedLocation = Coordinates(7, 7);
    auto startLocation = Coordinates(0, 0);
    auto expectedEndLocation = Coordinates(6, 6);

    auto returnCoordinates = Range::closestToMove(startLocation, targetedLocation, 5, map);
    CHECK_EQUAL(expectedEndLocation.getX(), returnCoordinates.getX());
    CHECK_EQUAL(expectedEndLocation.getY(), returnCoordinates.getY());
}

TEST(RangeTestsGroup, moveTestToOponent) {
    auto targetedLocation = Coordinates(7, 7);
    auto startLocation = Coordinates(0, 0);
    auto expectedEndLocation = Coordinates(5, 6);
    auto speed = 8;
    auto range = 3;

    auto returnCoordinates = Range::closestToMove(startLocation, targetedLocation, speed, map, range);
    CHECK_EQUAL(expectedEndLocation.getX(), returnCoordinates.getX());
    CHECK_EQUAL(expectedEndLocation.getY(), returnCoordinates.getY());
}

TEST(RangeTestsGroup, moveTestToOponentAndEnemyUnitColliding) {
    auto targetedLocation = Coordinates(7, 7);
    auto startLocation = Coordinates(0, 0);
    auto expectedEndLocation = Coordinates(6, 5);
    auto speed = 8;
    auto range = 3;

    static_cast<void>(dynamic_cast<WorkerUnit *>(unitFactory->createUnit(UnitType::Type::Worker,
                                                       Owner{Owner::OwnerType::Enemy},
                                                       Coordinates{5, 6}, Coordinates{5, 6},
                                                       Coordinates{5, 6}, 0,
                                                       Unit::UnitState::Standing)));
    auto returnCoordinates = Range::closestToMove(startLocation, targetedLocation, speed, map, range,
                                                  unitFactory->getEnemyUnits());
    CHECK_EQUAL(expectedEndLocation.getX(), returnCoordinates.getX());
    CHECK_EQUAL(expectedEndLocation.getY(), returnCoordinates.getY());
    CHECK_EQUAL(range, Range::countDistance(returnCoordinates, targetedLocation));
}