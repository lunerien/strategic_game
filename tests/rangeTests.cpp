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
    auto returnCoordinates = Range::closestToMove(Coordinates(0,0), Coordinates(7,7), 4, map);
    CHECK_EQUAL(Coordinates(4,4).getX(),returnCoordinates.getX());
    CHECK_EQUAL(Coordinates(4,4).getY(), returnCoordinates.getY());
}

TEST(RangeTestsGroup, moveTestToOponent)
{
    auto returnCoordinates = Range::closestToMove(Coordinates(0,0), Coordinates(7,7), 4, map, 2);
    CHECK_EQUAL(Coordinates(3,3).getX(), returnCoordinates.getX());
    CHECK_EQUAL(Coordinates(3,3).getY(), returnCoordinates.getY());
}