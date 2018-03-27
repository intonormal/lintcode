//
// Created by huangzewu on 27/03/2018.
//
#include "length.h"

Length_Unit Length_Factor::getMinUnit() {
    return Length_Unit::Inch;
}

string Length_Factor::getMinUnitString() {
    return "Inch";
}

lv_type Length_Factor::init() {
    static lv_type length_td;
    length_td.push_back(make_tuple(Length_Unit::Mile, "Mile", 63360));
    length_td.push_back(make_tuple(Length_Unit::Yard, "Yard", 36));
    length_td.push_back(make_tuple(Length_Unit::Feet, "Feet", 12));
    length_td.push_back(make_tuple(Length_Unit::Inch, "Inch", 1));
    return length_td;
}