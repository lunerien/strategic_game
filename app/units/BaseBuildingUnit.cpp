//
// Created by lukasz.kala on 15.07.2023.
//

#include "BaseBuildingUnit.h"

void BaseBuildingUnit::update(Map map, std::vector<Unit> units) {
    (void) map;
    (void) units;
}

std::string BaseBuildingUnit::dumpObject() {
    return std::string(BaseUnit::dumpObject() + " " + std::to_string(static_cast<int>(baseBuildingState)) + " " +  actualUnitBeingCreatedType.getUnitSign() + " " +  std::to_string(timeLeftToCreateUnit));
}
