//
// Created by lukasz.kala on 15.07.2023.
//

#include "BaseUnit.h"
#include "../utils/Range.h"
#include "../Action.h"

void BaseUnit::move(Coordinates coordinates) {
    if (movesLeft) {
        auto destLocation = Range::closestToMove(actualLocation, coordinates, speed, &map);
        actualLocation = destLocation;
        movesLeft -= Range::countDistance(actualLocation, destLocation);
        actions.emplace_back(Action::createMoveAction(Id{ID}, coordinates));
    }
}

void BaseUnit::attack(Unit &unit) {
    if(movesLeft){
        unit.takeHit(getAttackPower(&unit));
        actions.emplace_back(Action::createAttackAction(Id{ID}, Id{unit.getId()}));
        movesLeft = 0;
    }
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


Unit::UnitState BaseUnit::getState() {
    return state;
}

int BaseUnit::getAttackPower(Unit *) {
    return attackPowers[type.getType()];
}

void BaseUnit::update() {
}

std::string BaseUnit::dumpObject() {
    return std::string() + owner.getOwnerSign() + " " + type.getUnitSign() + " " + std::to_string(ID) + " " +
           std::to_string(actualLocation.getX()) + " " + std::to_string(actualLocation.getY()) + " " +
           std::to_string(stamina);

}

std::string BaseUnit::dumpObjectAction() {
    std::string actionsStrings;
    for (const auto& actionString: actions) {
        actionsStrings += actionString + "\n";
    }
    return actionsStrings;
}

std::string BaseUnit::dumpObjectAdditionalInfo() {
    return {std::to_string(ID) + " " + std::to_string(targetLocation.getX()) + " " +
            std::to_string(targetLocation.getY()) + " " + std::to_string(targetedLocationGlobalState.getX()) + " " +
            std::to_string(targetedLocationGlobalState.getY()) + " " + std::to_string(static_cast<int>(state))};
}

int BaseUnit::getDistanceToTarget() {
    return Range::countDistance(actualLocation, targetLocation);
}
