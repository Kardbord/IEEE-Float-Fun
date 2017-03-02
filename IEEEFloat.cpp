//
// Created by Tanner on 3/1/2017.
//

#include <bitset>
#include <sstream>
#include <iostream>
#include <cmath>
#include "IEEEFloat.h"

std::string IEEEFloat::toFloat(int const &integer, double const &decimal) {

    if (decimal > 1 && decimal < -1){
        throw "Parameters are not as promised -- one of the following occurred:\n"
                "1. -1 < integer < 1 is illegal parameter\n"
                "2. -1 < decimal > 1 is illegal parameter\n";
    }

    if (integer == 0 && decimal == 0) {
        std::string theFloat = std::bitset<M_REGISTER_BITS>(0).to_string();
        return theFloat;
    }

    int signBit = 0;
    if (integer < 0) signBit = 1;

    std::string binInt = std::bitset<M_REGISTER_BITS>((unsigned long long int) std::abs(integer)).to_string();
    binInt.erase(0, binInt.find_first_not_of('0'));

    std::vector<int> mantissa;

    // begin indexing at 1 b/c we don't want the first bit due to normalization
    for (int i = 1; i < binInt.size(); ++i) {
        mantissa.push_back((binInt[i] - '0'));
    }

    if (binInt.size() > 0) {
        decAppendMantissa(mantissa, decimal);
        int exponent = (int) (binInt.size() - 1);
        exponent += M_BIAS;
        std::string binExponent = std::bitset<M_EXPONENT_BITS>((unsigned long long int) exponent).to_string();

        std::stringstream ss;

        ss << signBit << binExponent;
        for (auto &&bit : mantissa) {
            ss << bit;
        }
        return ss.str();

    } else {
        // here exponent will end up being (mantissa.size - 1) because -1 < numWeAreConverting < 1 and so we have to
        // normalize the decimal we are given rather than just append it to the normalized number we're given
        int exponent;
        decToMantissa(mantissa, exponent, decimal);

        exponent += M_BIAS;
        std::string binExponent = std::bitset<M_EXPONENT_BITS>((unsigned long long int) exponent).to_string();

        std::stringstream ss;

        ss << signBit << binExponent;
        for (auto &&bit : mantissa) {
            ss << bit;
        }

        return ss.str();
    }


}

void IEEEFloat::decAppendMantissa(std::vector<int> &mantissa, double const &decimal) {

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
            if (tempDec > 1) tempDec -= 0.00001;
        } else mantissa.push_back(0);
    }
}

void IEEEFloat::decToMantissa(std::vector<int> &mantissa, int &exponent, double const &decimal) {
    double tempDec = decimal;

    if (decimal == 0) return; // TODO: check for empty mantissa on return

    while (mantissa.size() < M_MANTISSA_BITS) {
        tempDec *= 2;
        if (tempDec > 1) {
            mantissa.push_back(1);
            tempDec -= 1;
            if (tempDec > 1) tempDec -= 0.00001;
        } else mantissa.push_back(0);
    }

    for (int i = 0; i < 1; i) {
        if (mantissa[i] < 1) {
            mantissa.erase(mantissa.begin() + i);
        } else {
            exponent = -(i + 3); // weird math I know... but draw it out on a white board
            i = 1;
        }
    }

    mantissa.erase(mantissa.begin());

    while (mantissa.size() < M_MANTISSA_BITS) {
        mantissa.push_back(0);
    }
}
