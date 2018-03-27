//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_VOLUME_H
#define LINTCODE_VOLUME_H

#include "measure.hpp"
#include "common.h"

enum Volume_Unit {
    TSP = 1,
    TBSP = 3*TSP,
    OZ = 2*TBSP
};

struct Volume_Factor {
    static Volume_Unit getMinUnit() {
        return Volume_Unit::TSP;
    }
};

using Volume = Measure<Volume_Unit, Volume_Factor>;



#endif //LINTCODE_VOLUME_H