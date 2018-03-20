//
// Created by huangzewu on 20/03/2018.
//

#include "length.h"


Length::Length(int num, Length_Unit unit) : num_(num), unit_(unit) {/**/}

int Length::toMinUnit() const {
    return num_*unit_;
}

bool Length::operator==(const Length& right) const {
    return this->toMinUnit() == right.toMinUnit();
}