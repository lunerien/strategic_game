//
// Created by lukasz.kala on 13.07.2023.
//

#ifndef UNITFACTORY_H_E118644C764A4E6FBCFDC10F9FE36D18
#define UNITFACTORY_H_E118644C764A4E6FBCFDC10F9FE36D18


#include "WorkerUnit.h"
#include "Unit.h"

class UnitFactory {
public:
    enum class FactoryState
    {
        Idle,
        Building
    };
    UnitFactory(Owner owner, FactoryState factoryState, Map map) : owner(owner), factoryState(factoryState), map(map) {}
    void update();
    void loadUnits(std::vector<Unit> units);
    std::vector<Unit>& getUnits();
private:
    Unit* createUnit(UnitType type);
    const Owner owner;
    std::vector<Unit> units;
    FactoryState factoryState;
    Map map;




};


#endif //UNITFACTORY_H_E118644C764A4E6FBCFDC10F9FE36D18
