//
// Created by lukasz.kala on 16.07.2023.
//

#ifndef GOLDSTASH_H_CD44BAF2230747ADB4B8FAC0711CE348
#define GOLDSTASH_H_CD44BAF2230747ADB4B8FAC0711CE348


class GoldStash {
public:
    GoldStash():gold(2000){}
    explicit GoldStash(int gold):gold(gold){}
    int getGold() const{return gold;}
    void mineGold(){this->gold += 200;}
private:
    int gold;
};


#endif //GOLDSTASH_H_CD44BAF2230747ADB4B8FAC0711CE348
