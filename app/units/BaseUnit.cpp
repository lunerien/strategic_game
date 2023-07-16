//
// Created by lukasz.kala on 15.07.2023.
//

#include "BaseUnit.h"
#include "../utils/Range.h"

void BaseUnit::move(Coordinates coordinates) {
    actualLocation = Range::closestToMove(actualLocation, coordinates, speed, &map);
}

void BaseUnit::attack(Unit &unit) {
    unit.takeHit(getAttackPower(&unit));
}

void BaseUnit::takeHit(int opponentAttackPower) {
    if (stamina < opponentAttackPower) {
        stamina = 0;
    } else {
        stamina -= opponentAttackPower;
    }
}

char BaseUnit::getUnitSign() {
    return type.getUnitSign();
}

int BaseUnit::getActualStamina() {
    return stamina;
}

int BaseUnit::getAttackRange() {
    return stamina;
}

int BaseUnit::getSpeed() {
    return speed;
}

int BaseUnit::getId() {
    return ID;
}

int BaseUnit::getPrice() {
    return price;
}

int BaseUnit::getBuildTime() {
    return buildTime;
}

Coordinates BaseUnit::getActualLocation() {
    return actualLocation;
}


Owner BaseUnit::getOwner() {
    return owner;
}

UnitType BaseUnit::getType() {
    return type;
}

std::string BaseUnit::dumpObject() {
    return {std::string() + type.getUnitSign() + " " + std::to_string(ID) + " " + std::to_string(stamina) + " " +
            std::to_string(actualLocation.getX()) + " " + std::to_string(actualLocation.getY()) + " " +
            owner.getOwnerSign() + " " + std::to_string(targetLocation.getX()) + " " +
            std::to_string(targetLocation.getY()) + " " + std::to_string(targetedLocationGlobalState.getX()) + " " +
            std::to_string(targetedLocationGlobalState.getY()) + " " +  std::to_string(static_cast<int>(state))};
}

Unit::UnitState BaseUnit::getState() {
    return state;
}

int BaseUnit::getAttackPower(Unit *) {
    return 0;
}

void BaseUnit::update(Map, std::vector<Unit>) {
}
