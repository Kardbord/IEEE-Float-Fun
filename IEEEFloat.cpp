//
// Created by Tanner on 3/1/2017.
//

#include <bitset>
#include <sstream>
#include <cmath>
#include "IEEEFloat.h"

std::string IEEEFloat::toFloat(float const &num) {

    // Compute sign bit
    std::string signBit = computeSignBit(num);

    // Represent the number in base two scientific notation to later compute the exponent and mantissa bits
    BaseTwoSciNumber numBaseTwo(num);

    // Compute exponent bits
    std::string expBits = computeExponentBits(numBaseTwo);

    // Compute Mantissa bits
    std::string mantBits = computeMantissaBits(numBaseTwo);

    // Concatenate strings to get the final product
    return signBit + expBits + mantBits;
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

std::string IEEEFloat::computeMantissaBits(BaseTwoSciNumber const &numBaseTwo) {
    double mantissa = std::abs(numBaseTwo.getCoefficient());

    std::string mantissaBits = "";

    for (int i = 0; i < M_MANTISSA_BITS; ++i) {
        if (mantissa >= 1) --mantissa;
        mantissa *= 2;
        if (mantissa >= 1) mantissaBits += "1";
        else mantissaBits += "0";
    }

    return mantissaBits;
}
