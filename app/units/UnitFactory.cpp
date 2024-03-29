//
// Created by lukasz.kala on 13.07.2023.
//

#include "UnitFactory.h"

#include <utility>
#include <sstream>
#include <algorithm>
#include "WarUnit.h"
#include "BaseBuildingUnit.h"

Unit *UnitFactory::createUnit(UnitType::Type type, Owner owner, Coordinates actualLocation,
                              Coordinates targetedLocationGlobalState, Coordinates targetLocation,
                              int unitTypeState, Unit::UnitState unitState,
                              Stamina stamina, Id id) {
    int newId;
    if (id.ID == -1) {
        newId = getNewId();
    } else {
        newId = id.ID;
    }
    if (!isIdAvailable(newId)) {
        throw std::invalid_argument("Id is not available");
    }

    Unit *newUnit = nullptr;
    switch (type) {
        case UnitType::Type::Worker: {
            int unitStamina = 20;
            if (stamina.stamina != 0) {
                unitStamina = stamina.stamina;
            }
            newUnit = new WorkerUnit(
                    {Id{newId}, Stamina{unitStamina}, AttackRange{1}, Speed{1}, Price{100}, BuildTime{2},
                     actualLocation, owner, UnitType{UnitType::Type::Worker},
                     targetedLocationGlobalState, targetLocation, map,
                     {{UnitType::Type::Knight, 5}, {UnitType::Type::Swordsman, 5}, {UnitType::Type::Archer, 5},
                      {UnitType::Type::Pikeman, 5}, {UnitType::Type::Catapult, 5}, {UnitType::Type::Ram, 5},
                      {UnitType::Type::Worker, 5}, {UnitType::Type::Base, 1}}, playersUnits.units,
                     enemyUnits.units, unitState}, static_cast<WorkerUnit::WorkerState>(unitTypeState), goldStash);
            break;
        }
        case UnitType::Type::Knight: {
            int unitStamina = 70;
            if (stamina.stamina != 0) {
                unitStamina = stamina.stamina;
            }
            newUnit = new WarUnit(
                    {Id{newId}, Stamina{unitStamina}, AttackRange{1}, Speed{5}, Price{400}, BuildTime{5},
                     actualLocation, owner, UnitType{UnitType::Type::Knight},
                     targetedLocationGlobalState, targetLocation, map,
                     {{UnitType::Type::Knight, 35}, {UnitType::Type::Swordsman, 35}, {UnitType::Type::Archer, 35},
                      {UnitType::Type::Pikeman, 35}, {UnitType::Type::Catapult, 35}, {UnitType::Type::Ram, 50},
                      {UnitType::Type::Worker, 35}, {UnitType::Type::Base, 35}}, playersUnits.units,
                     enemyUnits.units, unitState},
                    static_cast<WarUnit::MeleState>(unitTypeState));
            break;
        }
        case UnitType::Type::Swordsman: {
            int unitStamina = 60;
            if (stamina.stamina != 0) {
                unitStamina = stamina.stamina;
            }
            newUnit = new WarUnit(
                    {Id{newId}, Stamina{unitStamina}, AttackRange{1}, Speed{2}, Price{250}, BuildTime{3},
                     actualLocation, owner, UnitType{UnitType::Type::Swordsman},
                     targetedLocationGlobalState, targetLocation, map,
                     {{UnitType::Type::Knight, 30}, {UnitType::Type::Swordsman, 30}, {UnitType::Type::Archer, 30},
                      {UnitType::Type::Pikeman, 20}, {UnitType::Type::Catapult, 20}, {UnitType::Type::Ram, 30},
                      {UnitType::Type::Worker, 30}, {UnitType::Type::Base, 30}}, playersUnits.units,
                     enemyUnits.units, unitState},
                    static_cast<WarUnit::MeleState>(unitTypeState));
            break;
        }
        case UnitType::Type::Archer: {
            int unitStamina = 40;
            if (stamina.stamina != 0) {
                unitStamina = stamina.stamina;
            }
            newUnit = new WarUnit(
                    {Id{newId}, Stamina{unitStamina}, AttackRange{5}, Speed{2}, Price{250}, BuildTime{3},
                     actualLocation, owner, UnitType{UnitType::Type::Archer},
                     targetedLocationGlobalState, targetLocation, map,
                     {{UnitType::Type::Knight, 15}, {UnitType::Type::Swordsman, 15}, {UnitType::Type::Archer, 15},
                      {UnitType::Type::Pikeman, 15}, {UnitType::Type::Catapult, 10}, {UnitType::Type::Ram, 10},
                      {UnitType::Type::Worker, 15}, {UnitType::Type::Base, 1}}, playersUnits.units,
                     enemyUnits.units, unitState},
                    static_cast<WarUnit::MeleState>(unitTypeState));
            break;
        }

        case UnitType::Type::Pikeman: {
            int unitStamina = 50;
            if (stamina.stamina != 0) {
                unitStamina = stamina.stamina;
            }
            newUnit = new WarUnit(
                    {Id{newId}, Stamina{unitStamina}, AttackRange{2}, Speed{2}, Price{200}, BuildTime{3},
                     actualLocation, owner, UnitType{UnitType::Type::Pikeman},
                     targetedLocationGlobalState, targetLocation, map,
                     {{UnitType::Type::Knight, 35}, {UnitType::Type::Swordsman, 15}, {UnitType::Type::Archer, 15},
                      {UnitType::Type::Pikeman, 15}, {UnitType::Type::Catapult, 15}, {UnitType::Type::Ram, 10},
                      {UnitType::Type::Worker, 15}, {UnitType::Type::Base, 10}}, playersUnits.units,
                     enemyUnits.units, unitState},
                    static_cast<WarUnit::MeleState>(unitTypeState));
            break;
        }

        case UnitType::Type::Ram: {
            int unitStamina = 90;
            if (stamina.stamina != 0) {
                unitStamina = stamina.stamina;
            }
            newUnit = new WarUnit(
                    {Id{newId}, Stamina{unitStamina}, AttackRange{1}, Speed{2}, Price{500}, BuildTime{4},
                     actualLocation, owner, UnitType{UnitType::Type::Ram},
                     targetedLocationGlobalState, targetLocation, map,
                     {{UnitType::Type::Knight, 10}, {UnitType::Type::Swordsman, 10}, {UnitType::Type::Archer, 10},
                      {UnitType::Type::Pikeman, 10}, {UnitType::Type::Catapult, 10}, {UnitType::Type::Ram, 10},
                      {UnitType::Type::Worker, 10}, {UnitType::Type::Base, 50}}, playersUnits.units,
                     enemyUnits.units, unitState},
                    static_cast<WarUnit::MeleState>(unitTypeState));
            break;
        }

        case UnitType::Type::Catapult: {
            int unitStamina = 50;
            if (stamina.stamina != 0) {
                unitStamina = stamina.stamina;
            }
            newUnit = new WarUnit(
                    {Id{newId}, Stamina{unitStamina}, AttackRange{7}, Speed{2}, Price{800}, BuildTime{6},
                     actualLocation, owner, UnitType{UnitType::Type::Catapult},
                     targetedLocationGlobalState, targetLocation, map,
                     {{UnitType::Type::Knight, 40}, {UnitType::Type::Swordsman, 40}, {UnitType::Type::Archer, 40},
                      {UnitType::Type::Pikeman, 40}, {UnitType::Type::Catapult, 40}, {UnitType::Type::Ram, 40},
                      {UnitType::Type::Worker, 40}, {UnitType::Type::Base, 50}}, playersUnits.units,
                     enemyUnits.units, unitState},
                    static_cast<WarUnit::MeleState>(unitTypeState));
            break;
        }

            // Use separate method for creating base building
        case UnitType::Type::Base: {
            break;
        }
    }
    if (owner.getOwner() == Owner::OwnerType::Player) {
        playersUnits.units.push_back(newUnit);
    } else {
        enemyUnits.units.push_back(newUnit);
    }
    return newUnit;
}

void UnitFactory::update() {

}


std::vector<Unit *> &UnitFactory::getPlayerUnits() {
    return playersUnits.units;
}

std::vector<Unit *> &UnitFactory::getEnemyUnits() {
    return enemyUnits.units;
}

bool UnitFactory::isIdAvailable(int id) {
    for (auto &unit: playersUnits.units) {
        if (unit->getId() == id) {
            return false;
        }
    }
    for (auto &unit: enemyUnits.units) {
        if (unit->getId() == id) {
            return false;
        }
    }
    return true;
}

int UnitFactory::getNewId() {
    int playerUnitsId = 0;
    for (auto unit: playersUnits.units) {
        if (unit->getId() == playerUnitsId) {
            playerUnitsId++;
        }
    }
    int opponentsUnitsId = 0;
    for (auto unit: enemyUnits.units) {
        if (unit->getId() == opponentsUnitsId) {
            opponentsUnitsId++;
        }
    }
    int smallerId = playerUnitsId < opponentsUnitsId ? playerUnitsId : opponentsUnitsId;
    int biggerId = playerUnitsId > opponentsUnitsId ? playerUnitsId : opponentsUnitsId;
    if (isIdAvailable(smallerId)) {
        if (smallerId > 1000) {
            throw std::out_of_range("Id is too big");
        }
        return smallerId;
    } else if (isIdAvailable(biggerId)) {
        if (biggerId > 1000) {
            throw std::out_of_range("Id is too big");
        }
        return biggerId;
    }

    if (biggerId + 1 > 1000) {
        throw std::out_of_range("Id is too big");
    }
    return biggerId + 1;
}


Unit *
UnitFactory::createBase(Owner owner, Coordinates actualLocation, Coordinates targetedLocationGlobalState,
                        Coordinates targetLocation, int unitTypeState, Unit::UnitState unitState,
                        int timeLeftToCreateUnit, UnitType actualUnitBeingCreatedType, Stamina stamina, Id id) {
    int newId;
    BaseBuildingUnit *newBase;
    if (id.ID == -1) {
        newId = getNewId();
    } else {
        newId = id.ID;
    }
    if (!isIdAvailable(newId)) {
        throw std::invalid_argument("Id is not available");
    }
    int unitStamina = 200;
    if (stamina.stamina != 0) {
        unitStamina = stamina.stamina;
    }
    // User already has base - don't create base
    if (owner.getOwner() == Owner::OwnerType::Player &&
        std::find_if(playersUnits.units.begin(), playersUnits.units.end(),
                     [](Unit *l) {
                         return dynamic_cast<BaseUnit *>(l)->getType().getType() == UnitType::Type::Base;
                     }) !=
        playersUnits.units.end()) {
        return nullptr;
    }

    newBase = new BaseBuildingUnit(
            {Id{newId}, Stamina{unitStamina}, AttackRange{1}, Speed{1}, Price{100}, BuildTime{2},
             actualLocation, owner, UnitType{UnitType::Type::Base},
             targetedLocationGlobalState, targetLocation, map,
             {{UnitType::Type::Knight, 0}, {UnitType::Type::Swordsman, 0}, {UnitType::Type::Archer, 0},
              {UnitType::Type::Pikeman, 0}, {UnitType::Type::Catapult, 0}, {UnitType::Type::Ram, 0},
              {UnitType::Type::Worker, 0}, {UnitType::Type::Base, 0}}, playersUnits.units, enemyUnits.units, unitState},
            static_cast<BaseBuildingUnit::BaseBuildingState>(unitTypeState), std::move(actualUnitBeingCreatedType),
            timeLeftToCreateUnit, *this, goldStash);
    if (owner.getOwner() == Owner::OwnerType::Player) {
        playersUnits.units.push_back(newBase);
    } else {
        enemyUnits.units.push_back(newBase);
    }
    return newBase;
}

Unit *UnitFactory::createUnit(const std::string &unitString, const std::string &unitAdditionalInfo) {
    std::vector<std::string> unitStringSplit;
    std::vector<std::string> unitAdditionalInfoStringSplit;
    auto tokenizedUnitString = std::istringstream{unitString};
    auto tokenizedUnitAdditionalInfo = std::istringstream{unitAdditionalInfo};
    auto stringToken = std::string{};

    //Tokenize unit string by space
    while (tokenizedUnitString >> stringToken) {
        unitStringSplit.push_back(stringToken);
    }

    //Tokenize unit additional info string by space
    while (tokenizedUnitAdditionalInfo >> stringToken) {
        unitAdditionalInfoStringSplit.push_back(stringToken);
    }

    //Set unit parameters from unit string
    Owner owner{unitStringSplit[0][0]};
    UnitType type(unitStringSplit[1][0]);
    Id id{std::stoi(unitStringSplit[2])};
    Coordinates actualLocation{std::stoi(unitStringSplit[3]), std::stoi(unitStringSplit[4])};
    Stamina stamina{std::stoi(unitStringSplit[5])};


    //Set unit parameters from unit additional info string
//    Id id{std::stoi(unitAdditionalInfoStringSplit[0])};
    Coordinates targetedLocation{std::stoi(unitAdditionalInfoStringSplit[1]),
                                 std::stoi(unitAdditionalInfoStringSplit[2])};
    Coordinates targetLocationGlobalState{std::stoi(unitAdditionalInfoStringSplit[3]),
                                          std::stoi(unitAdditionalInfoStringSplit[4])};
    auto unitState = static_cast<Unit::UnitState>(std::stoi(unitAdditionalInfoStringSplit[5]));
    int unitTypeState = std::stoi(unitAdditionalInfoStringSplit[6]);

    if (type.getType() == UnitType::Type::Base) {
        UnitType actualUnitBeingCreatedType(unitStringSplit[6][0]);
        int timeLeftToCreateUnit = std::stoi(unitAdditionalInfoStringSplit[7]);
        return createBase(owner, actualLocation, targetLocationGlobalState, targetedLocation, unitTypeState, unitState,
                          timeLeftToCreateUnit, actualUnitBeingCreatedType, stamina, id);
    }

    return createUnit(type.getType(), owner, actualLocation, targetLocationGlobalState, targetedLocation, unitTypeState,
                      unitState, stamina, id);
}


