//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_VOLUME_H
#define LINTCODE_VOLUME_H

enum Volume_Unit {
    OZ = 6,
    TBSP = 3,
    TSP = 1
};

struct Volume {
    Volume(int num, Volume_Unit unit) : num_(num), unit_(unit) {/**/}
    bool operator==(const Volume& right) const {
        return this->toMinUnit() == right.toMinUnit();
    }
private:
    int toMinUnit() const {
        return num_ * unit_;
    }
private:
    int num_;
    Volume_Unit unit_;
};


#endif //LINTCODE_VOLUME_H
