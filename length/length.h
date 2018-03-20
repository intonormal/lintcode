//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_LENGTH_H
#define LINTCODE_LENGTH_H

#include "measure.h"

enum Length_Unit {
    Mile = 63360,
    Yard = 36,
    Feet = 12,
    Inch = 1
};


struct Length {
    Length(int num, Length_Unit unit);
    bool operator==(const Length& right) const;

private:
    int toMinUnit() const;

private:
    int  num_;
    Length_Unit unit_;
};


#endif //LINTCODE_LENGTH_H
