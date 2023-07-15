//
// Created by lukasz.kala on 12.07.2023.
//

#ifndef UNITTYPE_H_7D99974E11FD41F4A868CFE0452F217C
#define UNITTYPE_H_7D99974E11FD41F4A868CFE0452F217C


class UnitType {
public:
    enum class Type : int
    {
        Knight = 1,
        Swordsman,
        Archer,
        Pikeman,
        Ram,
        Catapult,
        Worker,
        Base
    };

    UnitType(Type type, char sign):type(type),sign(sign){}

    virtual char getUnitSign(){return sign;}
    virtual Type getType(){return type;}
private:
    Type type;
    char sign;
};


#endif //UNITTYPE_H_7D99974E11FD41F4A868CFE0452F217C
