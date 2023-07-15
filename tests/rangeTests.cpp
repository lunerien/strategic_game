//
// Created by lukasz on 09.07.23.
//

#include "../app/utils/Range.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(RangeTestsGroup)
{
    void setup()
    {
        map = new Map({
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'}
        });
    }

    void teardown()
    {
        delete map;
    }

    Map* map;
};


TEST(RangeTestsGroup, moveTest)
{
    auto targetedLocation = Coordinates(7,7);
    auto startLocation = Coordinates(0,0);
    auto expectedEndLocation = Coordinates(4,4);

    auto returnCoordinates = Range::closestToMove(startLocation, targetedLocation, 4, map);
    CHECK_EQUAL(expectedEndLocation.getX(), returnCoordinates.getX());
    CHECK_EQUAL(expectedEndLocation.getY(), returnCoordinates.getY());
}

TEST(RangeTestsGroup, moveTestToOponent)
{
    auto targetedLocation = Coordinates(7,7);
    auto startLocation = Coordinates(0,0);
    auto expectedEndLocation = Coordinates(6,6);
    auto speed = 7;
    auto range = 2;

    auto returnCoordinates = Range::closestToMove(startLocation, targetedLocation, speed, map, range);
    CHECK_EQUAL(expectedEndLocation.getX(), returnCoordinates.getX());
    CHECK_EQUAL(expectedEndLocation.getY(), returnCoordinates.getY());
}