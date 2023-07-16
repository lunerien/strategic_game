//
// Created by lukasz.kala on 13.07.2023.
//

#ifndef UNITFACTORY_H_E118644C764A4E6FBCFDC10F9FE36D18
#define UNITFACTORY_H_E118644C764A4E6FBCFDC10F9FE36D18


#include <utility>

#include "WorkerUnit.h"
#include "Unit.h"

class UnitFactory {
public:

    UnitFactory(Owner ownerPlayer, Owner ownerEnemy, Map map) :
            playersUnits({std::vector<Unit*>(), ownerPlayer}), enemyUnits({std::vector<Unit*>(), ownerEnemy}),
            map(std::move(map)) {}

    void update();

    std::vector<Unit*> &getPlayerUnits();

    std::vector<Unit*> &getEnemyUnits();

    bool isIdAvailable(int id);

    int getNewId();

    Unit *createUnit(UnitType::Type type, Owner owner, Coordinates actualLocation,
                     Coordinates targetedLocationGlobalState, Coordinates targetLocation,
                     int unitTypeState, Unit::UnitState unitState, Stamina stamina = Stamina{0}, Id id = Id{-1});

    Unit *createUnit(const std::string& unitString, const std::string& unitAdditionalInfo);

    Unit *createBase(Owner owner, Coordinates actualLocation, Coordinates targetedLocationGlobalState,
                     Coordinates targetLocation, int unitTypeState, Unit::UnitState unitState,
                     int timeLeftToCreateUnit, UnitType actualUnitBeingCreatedType, Stamina stamina  = Stamina{0} , Id id = Id{-1});
    ~UnitFactory() {
        for (auto &unit: playersUnits.units) {
            delete unit;
        }
        for (auto &unit: enemyUnits.units) {
            delete unit;
        }
    }

private:
    struct SideUnits {
        std::vector<Unit*> units;
        const Owner owner;
    };
    SideUnits playersUnits;
    SideUnits enemyUnits;

    Map map;


};


#endif //UNITFACTORY_H_E118644C764A4E6FBCFDC10F9FE36D18
