//
// Created by lukasz on 10.07.23.
//

#include <vector>
#include "WarUnit.h"


void WarUnit::update(Map map, std::vector<Unit> units) {
    (void) map;
    (void) units;
}

std::string WarUnit::dumpObject() {
    return BaseUnit::dumpObject() + std::to_string(static_cast<int>(meleState));
}
