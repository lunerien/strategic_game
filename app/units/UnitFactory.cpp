//
// Created by lukasz.kala on 13.07.2023.
//

#include "UnitFactory.h"
#include "WarUnit.h"

Unit *UnitFactory::createUnit(UnitType type) {
    switch (type.getType()) {
        case UnitType::Type::Worker:
            return new WorkerUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                   Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                   Coordinates{0, 0}, map}, WorkerUnit::WorkerState::GoingToMine);
        case UnitType::Type::Knight:
            return new WarUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                Coordinates{0, 0}, map}, WarUnit::MeleState::ProtectingBase);
        case UnitType::Type::Swordsman:
            return new WarUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                Coordinates{0, 0}, map}, WarUnit::MeleState::ProtectingBase);
            break;
        case UnitType::Type::Archer:
            return new WarUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                Coordinates{0, 0}, map}, WarUnit::MeleState::ProtectingBase);
            break;
        case UnitType::Type::Pikeman:
            return new WarUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                Coordinates{0, 0}, map}, WarUnit::MeleState::ProtectingBase);
            break;
        case UnitType::Type::Ram:
            return new WarUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                Coordinates{0, 0}, map}, WarUnit::MeleState::ProtectingBase);
            break;
        case UnitType::Type::Catapult:
            return new WarUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                Coordinates{0, 0}, map}, WarUnit::MeleState::ProtectingBase);
            break;
        case UnitType::Type::Base:
            return new WarUnit({Id{0}, Stamina{9}, AttackRange{1}, Speed{1}, Price{1}, BuildTime{1}, Coordinates{0, 0},
                                Owner{Owner::OwnerType::Player, 'P'}, UnitType{UnitType::Type::Knight, 'K'}, Coordinates{0, 0},
                                Coordinates{0, 0}, map}, WarUnit::MeleState::ProtectingBase);
            break;
    }
    return nullptr;
}

void UnitFactory::update() {

}

void UnitFactory::loadUnits(std::vector<Unit> loadedUnits) {
    units = std::move(loadedUnits);

}

std::vector<Unit>& UnitFactory::getUnits() {
    return units;
}
