//
// Created by lukasz on 09.07.23.
//

#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
    CHECK_TRUE(true);
}