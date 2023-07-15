//
// Created by lukasz.kala on 13.07.2023.
//

#include "WorkerUnit.h"

void WorkerUnit::update(Map map, std::vector<Unit> units) {

}

Owner WorkerUnit::getOwner() {
    return Owner(Owner::OwnerType::Player, 0);
}

UnitType WorkerUnit::getType() {
    return UnitType(UnitType::Type::Worker, 0);
}

std::string WorkerUnit::dumpObject() {
    return std::to_string(id);
}

void WorkerUnit::move(Coordinates coordinates) {

}

void WorkerUnit::attack(Unit &unit) {
    unit.takeHit(getAttackPower(&unit));
}

void WorkerUnit::takeHit(int attackPower) {
    if (stamina < attackPower)
    {
        stamina = 0;
    }
    else
    {
        stamina -= attackPower;
    }
}

char WorkerUnit::getUnitSign() {
    return 'W';
}

int WorkerUnit::getActualStamina() {
    return stamina;
}

int WorkerUnit::getAttackRange() {
    return 1;
}

int WorkerUnit::getSpeed() {
    return 2;
}

int WorkerUnit::getId() {
    return id;
}

int WorkerUnit::getPrice() {
    return 100;
}

int WorkerUnit::getBuildTime() {
    return 2;
}

Coordinates WorkerUnit::getActualLocation() {
    return actualLocation;
}

Unit::UnitState WorkerUnit::getState() {
    return state;
}

int WorkerUnit::getAttackPower(Unit *unit) {
    switch (unit->getType().getType()) {
        case UnitType::Type::Base:
            return 1;
        default:
            return 5;
    }
}
