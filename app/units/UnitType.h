//
// Created by lukasz.kala on 12.07.2023.
//

#ifndef UNITTYPE_H_7D99974E11FD41F4A868CFE0452F217C
#define UNITTYPE_H_7D99974E11FD41F4A868CFE0452F217C


class UnitType {
public:
    enum class Type : char
    {
        Knight = 'K',
        Swordsman = 'S',
        Archer = 'A',
        Pikeman = 'P',
        Ram = 'R',
        Catapult = 'C',
        Worker = 'W',
        Base = 'B'
    };

    UnitType(Type type):type(type){}
    explicit UnitType(char type):type(static_cast<Type>(type)){}

    virtual char getUnitSign(){return static_cast<char>(Type(type));}
    virtual Type getType(){return type;}
private:
    Type type;
};


#endif //UNITTYPE_H_7D99974E11FD41F4A868CFE0452F217C
