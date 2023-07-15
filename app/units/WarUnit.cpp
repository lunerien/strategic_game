//
// Created by lukasz on 10.07.23.
//

#include <vector>
#include "WarUnit.h"
#include "../Map.h"
#include "../utils/Range.h"

void WarUnit::move(Coordinates coordinates) {
    actualLocation = Range::closestToMove(actualLocation, coordinates, speed, &map);
}

void WarUnit::attack(Unit &unit) {
    unit.takeHit(getAttackPower(&unit));
}

void WarUnit::takeHit(int opponentAttackPower) {
    if (stamina < opponentAttackPower) {
        stamina = 0;
    } else {
        stamina -= opponentAttackPower;
    }
}

char WarUnit::getUnitSign() {
    return type.getUnitSign();
}

int WarUnit::getActualStamina() {
    return stamina;
}

int WarUnit::getAttackRange() {
    return stamina;
}

int WarUnit::getSpeed() {
    return speed;
}

int WarUnit::getId() {
    return ID;
}

int WarUnit::getPrice() {
    return price;
}

int WarUnit::getBuildTime() {
    return buildTime;
}

Coordinates WarUnit::getActualLocation() {
    return actualLocation;
}

void WarUnit::update(Map map, std::vector<Unit> units) {
    (void) map;
    (void) units;
}

Owner WarUnit::getOwner() {
    return owner;
}

UnitType WarUnit::getType() {
    return type;
}

std::string WarUnit::dumpObject() {
    return {std::to_string(type.getUnitSign()) + " " + std::to_string(ID) + " " + std::to_string(stamina) + " " +
            std::to_string(attackRange) + " " + std::to_string(speed) + " " + std::to_string(price) + " " +
            std::to_string(buildTime) + " " + std::to_string(actualLocation.getX()) + " " +
            std::to_string(actualLocation.getY()) + " " + owner.getOwnerSign() + " " +
            std::to_string(targetLocation.getX()) + " " + std::to_string(targetLocation.getY()) + " " +
            std::to_string(targetedLocationGlobalState.getX()) + " " +
            std::to_string(targetedLocationGlobalState.getY()) + "\n"};
}

Unit::UnitState WarUnit::getState() {
    return state;
}

int WarUnit::getAttackPower(Unit *unit) {
    (void) unit;
    return 0;
}
