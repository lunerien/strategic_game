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
    void update();
private:
    Unit* createUnit(UnitType type);
    const Owner owner;
    std::vector<Unit> units;




};


#endif //UNITFACTORY_H_E118644C764A4E6FBCFDC10F9FE36D18
