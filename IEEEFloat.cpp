//
// Created by Tanner on 3/1/2017.
//

#include <bitset>
#include <sstream>
#include "IEEEFloat.h"

static std::string toFloat(double const &num) {

}

std::string IEEEFloat::computeSignBit(double const &num) {
    if (num < 0) return 1;
    else return 0;
}


