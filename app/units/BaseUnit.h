//
// Created by lukasz.kala on 15.07.2023.
//

#ifndef BASEUNIT_H_03FC5B71258B4CB4BA456992EE01C35A
#define BASEUNIT_H_03FC5B71258B4CB4BA456992EE01C35A


#include "Unit.h"

class BaseUnit : public Unit {
public:
    BaseUnit(Id ID, Stamina stamina, AttackRange attackRange, Speed speed, Price price, BuildTime buildTime,
             Coordinates actualLocation, Owner owner, UnitType type, Coordinates targetedLocationGlobalState,
             Coordinates targetLocation, Map &map, std::vector<AttackStat> attackStats, UnitState state = UnitState::Standing) :
            ID(ID.ID), stamina(stamina.stamina), attackRange(attackRange.attackRange), speed(speed.Speed),
            price(price.price), buildTime(buildTime.BuildTime), actualLocation(actualLocation),
            owner(owner), type(std::move(type)), targetedLocationGlobalState(targetedLocationGlobalState),
            targetLocation(targetLocation), state(state), map(map), attackStats(std::move(attackStats))
    {}

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

    UnitState getState() override;

    int getAttackPower(Unit *unit) override;

private:

    int ID;
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
    Map &map;
    std::vector<AttackStat> attackStats;
};


#endif //BASEUNIT_H_03FC5B71258B4CB4BA456992EE01C35A
