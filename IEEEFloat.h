//
// Created by Tanner on 3/1/2017.
//

#ifndef INTTOFLOAT_IEEEFLOAT_H
#define INTTOFLOAT_IEEEFLOAT_H

#include <vector>

class IEEEFloat {
public:

    /**
     * Takes, in two parts (see params), a number and returns a string containing the IEEE 32-bit binary representation
     * of that number.
     *
     * Example: Representing 53.01234 as it would be in memory as an IEEE float
     *      - Proper function call: toFloat(53, 0.01234);
     *
     * @param integer is everything left of the decimal point of the number you want represented as an IEEE flaot
     * @param decimal is everything right of the decimal point of the number you want represented as an IEEE float
     * @return a string containing the binary (IEEE) representation of the number you want represented as an IEEE float
     */
    static std::string toFloat(double const &num);

    static int getRegisterBits() { return M_REGISTER_BITS; }

    static int getExponentBits() { return M_EXPONENT_BITS; }

    static int getMantissaBits() { return M_MANTISSA_BITS; }

    static int getSignBits() { return M_SIGN_BITS; }

    static int getBias() { return M_BIAS; }

private:
    IEEEFloat() {}

    static const int M_REGISTER_BITS = 32;
    static const int M_EXPONENT_BITS = 8;
    static const int M_MANTISSA_BITS = 23;
    static const int M_SIGN_BITS = 1;

    static const int M_BIAS = 127;

    static std::string computeSignBit(double const &num);
};


#endif //INTTOFLOAT_IEEEFLOAT_H
