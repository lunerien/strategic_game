//
// Created by lukasz.kala on 13.07.2023.
//

#include "UnitFactory.h"
#include "WarUnit.h"

Unit *UnitFactory::createUnit(UnitType type) {
    switch (type.getType()) {
        case UnitType::Type::Worker:
            return new WorkerUnit();
        case UnitType::Type::Knight:
            return new WarUnit();
        case UnitType::Type::Swordsman:
            break;
        case UnitType::Type::Archer:
            break;
        case UnitType::Type::Pikeman:
            break;
        case UnitType::Type::Ram:
            break;
        case UnitType::Type::Catapult:
            break;
        case UnitType::Type::Base:
            break;
    }
    return nullptr;
}

void UnitFactory::update() {

}
