//
// Created by lukasz.kala on 13.07.2023.
//

#include "WorkerUnit.h"

void WorkerUnit::update(Map map, std::vector<Unit> units) {
    (void) map;
    (void) units;
}

std::string WorkerUnit::dumpObject() {
    return BaseUnit::dumpObject() + std::to_string(static_cast<int>(workerState));
}


int WorkerUnit::getAttackPower(Unit *unit) {
    switch (unit->getType().getType()) {
        case UnitType::Type::Base:
            return 1;
        default:
            return 5;
    }
}

