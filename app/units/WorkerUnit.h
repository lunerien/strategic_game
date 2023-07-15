//
// Created by lukasz.kala on 13.07.2023.
//

#ifndef WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9
#define WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9


#include "../Map.h"
#include "Unit.h"

#include <utility>

class WorkerUnit : public Unit {
    WorkerUnit(Id id, Stamina stamina, AttackRange attackRange, Speed speed, Price price, BuildTime buildTime,
               Coordinates actualLocation,
               Owner owner, UnitType type, Coordinates targetedLocationGlobalState, Coordinates targetLocation,
               UnitState state) :
            id(id.ID), stamina(stamina.stamina), attackRange(attackRange.attackRange), speed(speed.Speed),
            price(price.price), buildTime(buildTime.BuildTime),
            actualLocation(actualLocation), owner(owner), type(std::move(type)),
            targetedLocationGlobalState(targetedLocationGlobalState),
            targetLocation(targetLocation), state(state) {}

    void update(Map map, std::vector<Unit> units) override;

    Owner getOwner() override;

    UnitType getType() override;

    std::string dumpObject() override;

    void move(Coordinates coordinates) override;

    void attack(Unit &unit) override;

    void takeHit(int attackPower) override;

    char getUnitSign() override;

    int getActualStamina() override;

    int getAttackRange() override;

    int getSpeed() override;

    int getId() override;

    int getPrice() override;

    int getBuildTime() override;

    Coordinates getActualLocation() override;

    ~WorkerUnit() override = default;

    int getAttackPower(Unit *unit) override;

    UnitState getState() override;

private:

    enum class WorkerState {
        GoingToMine,
        InMine,
        FightingMine,
        FightingBase
    };

private:
    int id;
    int stamina;
    int attackRange;
    int speed;
    int price;
    int buildTime;
    Coordinates actualLocation;
    Owner owner;
    UnitType type;
    Coordinates targetedLocationGlobalState;
    Coordinates targetLocation;
    UnitState state;
};


#endif //WORKERUNIT_H_C82A6D645515446E93A03397A620F9C9
