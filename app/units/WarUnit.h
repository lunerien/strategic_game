//
// Created by lukasz on 10.07.23.
//

#ifndef STRATEGIC_GAME_WARUNIT_H
#define STRATEGIC_GAME_WARUNIT_H


#include "Unit.h"

#include <utility>

class WarUnit : public Unit {
public:
    WarUnit(Id ID, Stamina stamina, AttackRange attackRange, Speed speed, Price price, BuildTime buildTime,
            Coordinates actualLocation, Owner owner, UnitType type, Coordinates targetedLocationGlobalState,
            Coordinates targetLocation, Map &map, int attackPower, UnitState state = UnitState::Standing)
            : ID(ID.ID), stamina(stamina.stamina), attackRange(attackRange.attackRange), speed(speed.Speed),
              price(price.price), buildTime(buildTime.BuildTime), attackPower(attackPower),
              actualLocation(actualLocation),
              owner(owner), type(std::move(type)), targetedLocationGlobalState(targetedLocationGlobalState),
              targetLocation(targetLocation), state(state), map(map) {}

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

    ~WarUnit() override = default;

    enum class MeleState {
        ProtectingBase,
        GoingToAttack,
    };

private:
    int ID;
    int stamina;
    int attackRange;
    int speed;
    int price;
    int buildTime;
    int attackPower;
    Coordinates actualLocation;
    Owner owner;
    UnitType type;
    Coordinates targetedLocationGlobalState;
    Coordinates targetLocation;
    UnitState state;
    Map &map;

};


#endif //STRATEGIC_GAME_WARUNIT_H
