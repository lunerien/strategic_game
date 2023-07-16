//
// Created by lukasz.kala on 13.07.2023.
//

#include "WorkerUnit.h"
#include "../utils/Range.h"

void WorkerUnit::update() {
    switch (workerState) {
        case WorkerState::GoingToMine: {
            if (getDistanceToTarget() == 0) {
                workerState = WorkerState::InMine;
                break;
            }
            auto closestMine = Range::getClosestMine(BaseUnit::getActualLocation(), map);
            if (Range::isEnemyInPosition(closestMine, unitsEnemy)) {
                break;
            }
            move(closestMine);
            break;
        }
        case WorkerState::InMine:
            goldStash.mineGold();
            break;
        case WorkerState::FightingMine:

            break;
        case WorkerState::FightingBase:

            break;
    }
}


int WorkerUnit::getAttackPower(Unit *unit) {
    switch (unit->getType().getType()) {
        case UnitType::Type::Base:
            return 1;
        default:
            return 5;
    }
}

std::string WorkerUnit::dumpObjectAdditionalInfo() {
    return BaseUnit::dumpObjectAdditionalInfo()  + " " + std::to_string(static_cast<int>(workerState));
}

