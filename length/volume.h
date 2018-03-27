//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_VOLUME_H
#define LINTCODE_VOLUME_H

#include "measure.hpp"
#include "common.h"
#include <tuple>
#include <vector>

enum Volume_Unit {
    TSP = 1,
    TBSP = 3*TSP,
    OZ = 2*TBSP
};

using vv_type = vector<tuple<Volume_Unit, string, int>>;
struct Volume_Factor {
    static Volume_Unit getMinUnit();
    static vv_type init();
};

using Volume = Measure<Volume_Unit, Volume_Factor>;

#endif //LINTCODE_VOLUME_H
