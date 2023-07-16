//
// Created by lukasz.kala on 15.07.2023.
//

#include "BaseBuildingUnit.h"

void BaseBuildingUnit::update() {

}

std::string BaseBuildingUnit::dumpObject() {
    return {BaseUnit::dumpObject() + " " + actualUnitBeingCreatedType.getUnitSign()};
}

std::string BaseBuildingUnit::dumpObjectAdditionalInfo() {
    return {BaseUnit::dumpObjectAdditionalInfo() + " " + std::to_string(static_cast<int>(baseBuildingState)) + " " +
            std::to_string(timeLeftToCreateUnit)};
}

std::string BaseBuildingUnit::dumpObjectAction() {
    std::string buildAction =
            std::string() + BaseUnit::getOwner().getOwnerSign() + " " + 'B' + " " + std::to_string(BaseUnit::getId()) +
            " " + std::to_string(BaseUnit::getActualLocation().getX()) + " " +
            std::to_string(BaseUnit::getActualLocation().getY()) + " " + std::to_string(BaseUnit::getActualStamina());
    if (baseBuildingState == BaseBuildingState::CreatingUnit) {
        buildAction += std::string() + " " + actualUnitBeingCreatedType.getUnitSign();
    }
    return buildAction;
}

