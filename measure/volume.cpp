//
// Created by huangzewu on 27/03/2018.
//

#include "volume.h"

Volume_Unit Volume_Factor::getMinUnit() {
    return Volume_Unit::TSP;
}

string Volume_Factor::getMinUnitString() {
    return "TSP";
}

vv_type Volume_Factor::init() {
    static vv_type volume_td;
    volume_td.push_back(make_tuple(Volume_Unit::OZ, "OZ", 6));
    volume_td.push_back(make_tuple(Volume_Unit::TBSP, "TBSP", 3));
    volume_td.push_back(make_tuple(Volume_Unit::TSP, "TSP", 1));
    return volume_td;
}