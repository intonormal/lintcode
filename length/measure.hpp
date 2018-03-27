//
// Created by huangzewu on 20/03/2018.
//

#ifndef LINTCODE_MEASURE_H
#define LINTCODE_MEASURE_H
#include <string>
#include <tuple>
#include <vector>
using namespace std;

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

    const std::string print_to_descending() const {
        vector<tuple<T, string, int>> data = U::init();
        return do_print(data);
    }

    const std::string print_to_minUnit() const {
        return to_string(this->toMinUnit()) + " "+ U::getMinUnitString();
    }

private:
    string do_print(vector<tuple<T, string, int>> data) const {
        string result = "";
        int temp = num_ * unit_;
        for(auto iter=data.begin(); iter != data.end(); iter++) {
            int ret = temp / get<2>(*iter);
            temp -= ret * get<2>(*iter);
            if(ret!=0) {
                result += to_string(ret)+ " "+ get<1>(*iter) +" ";
            }
        }
        return result;
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
