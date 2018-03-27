//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_LENGTH_H
#define LINTCODE_LENGTH_H

#include "measure.hpp"
#include "common.h"
using namespace std;

enum Length_Unit {
    Inch = 1,
    Feet = 12 * Inch,
    Yard = 3 * Feet,
    Mile = 1760 * Yard
};

using lv_type = vector<tuple<Length_Unit, string, int>>;
struct Length_Factor {
    static Length_Unit getMinUnit();
    static string getMinUnitString();
    static lv_type init();
};

using Length = Measure<Length_Unit, Length_Factor>;

#endif //LINTCODE_LENGTH_H
