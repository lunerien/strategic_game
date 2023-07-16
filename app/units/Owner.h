//
// Created by lukasz.kala on 12.07.2023.
//

#ifndef OWNER_H_91448D76A9054379BEDF6ACE41633E68
#define OWNER_H_91448D76A9054379BEDF6ACE41633E68


class Owner {
public:
    enum class OwnerType: char
    {
        Player = 'P',
        Enemy = 'E',
    };

    explicit Owner(OwnerType type):type(type){}
    explicit Owner(char type):type(static_cast<OwnerType>(type)){}

    OwnerType getOwner(){return type;}
    char getOwnerSign() const{return static_cast<char>(OwnerType(type));}

private:
    OwnerType type;
};


#endif //OWNER_H_91448D76A9054379BEDF6ACE41633E68
