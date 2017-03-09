//
// Created by Tanner on 3/1/2017.
//

#include <bitset>
#include <sstream>
#include "IEEEFloat.h"

std::string IEEEFloat::toFloat(float const &num) {
    std::string signBit = computeSignBit(num);

    return "";
}

std::string IEEEFloat::computeSignBit(float const &num) {
    if (num < 0) return "1";
    else return "0";
}

