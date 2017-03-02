//
// Created by Tanner on 3/1/2017.
//

#include <bitset>
#include <sstream>
#include <iostream>
#include "IEEEFloat.h"

std::string IEEEFloat::toFloat(int const &integer, double const &decimal = 0) {
    int signBit = 0;
    if (integer < 0) signBit = 1;

    std::string binInt = std::bitset<M_REGISTER_BITS>((unsigned long long int) integer).to_string();
    binInt.erase(0, binInt.find_first_not_of('0'));

    std::vector<int> mantissa;

    // begin indexing at 1 b/c we don't want the first bit due to normalization
    for (int i = 1; i < binInt.size(); ++i) {
        mantissa.push_back((binInt[i] - '0'));
    }

    decToMantissa(mantissa, decimal);

    int exponent = (int) (binInt.size() - 1);
    exponent += M_BIAS;
    std::string binExponent = std::bitset<M_EXPONENT_BITS>((unsigned long long int) exponent).to_string();

    std::stringstream ss;

    ss << signBit << binExponent;
    for (auto &&bit : mantissa) {
        ss << bit;
    }

    return ss.str();
}

void IEEEFloat::decToMantissa(std::vector<int> &mantissa, double const &decimal) {

    double tempDec = decimal;

    if (decimal == 0) {
        while (mantissa.size() < M_MANTISSA_BITS) {
            mantissa.push_back(0);
        }
        return;
    }

    while (mantissa.size() < M_MANTISSA_BITS) {
        tempDec *= 2;
        if (tempDec > 1) {
            mantissa.push_back(1);
            tempDec -= 1;
            if (tempDec < 1) tempDec -= 0.00001;
        } else mantissa.push_back(0);
    }
}
