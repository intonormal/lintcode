//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_VOLUME_H
#define LINTCODE_VOLUME_H

#include "measure.h"

enum Volume_Unit {
    OZ = 6,
    TBSP = 3,
    TSP = 1
};

struct Volume : Measure<Volume_Unit> {
    Volume(int num, Volume_Unit unit) : Measure(num, unit) {/**/}
};


#endif //LINTCODE_VOLUME_H
