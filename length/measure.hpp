//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_MEASURE_H
#define LINTCODE_MEASURE_H
template< typename T, typename U>
struct Measure {
    Measure(int num, T unit) : num_(num), unit_(unit) {/**/}

    bool operator==(const Measure& right) const {
        return this->toMinUnit() == right.toMinUnit();
    }

    bool operator!=(const Measure& right) const {
        return this->toMinUnit() != right.toMinUnit();
    }

    const Measure<T, U> operator+(const Measure<T, U>& right) const {
        return Measure<T, U>(this->toMinUnit() + right.toMinUnit(), U::getMinUnit());
    }

protected:
    int toMinUnit() const {
        return num_ * unit_;
    }

private:
    int num_;
    T unit_;
};


#endif //LINTCODE_MEASURE_H
