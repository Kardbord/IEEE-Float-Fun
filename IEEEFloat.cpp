//
// Created by Tanner on 3/1/2017.
//

#include <bitset>
#include <sstream>
#include "IEEEFloat.h"

std::string IEEEFloat::toFloat(float const &num) {
    std::string signBit = computeSignBit(num);

    // Represent the number in base two scientific notation to later compute the exponent and mantissa bits
    BaseTwoSciNumber numBaseTwo(num);

    std::string expBits = computeExponentBits(numBaseTwo);


    return "";
}

std::string IEEEFloat::computeSignBit(float const &num) {
    if (num < 0) return "1";
    else return "0";
}

std::string IEEEFloat::computeExponentBits(BaseTwoSciNumber const &numBaseTwo) {

    // IEEE_Exponent = actualExponent + BIAS
    int exponent = numBaseTwo.getExponent() + M_BIAS;

    return std::bitset<M_EXPONENT_BITS>((unsigned long long int) exponent).to_string();
}

