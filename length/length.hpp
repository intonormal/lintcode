//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_LENGTH_H
#define LINTCODE_LENGTH_H

#include "measure.hpp"
#include "common.h"

enum Length_Unit {
    Inch = 1,
    Feet = 12 * Inch,
    Yard = 3 * Feet,
    Mile = 1760 * Yard
};


struct Length_Factor {
    static Length_Unit getMinUnit() {
        return Length_Unit::Inch;
    }
};



typedef Measure<Length_Unit, Length_Factor> Length;



#endif //LINTCODE_LENGTH_H
