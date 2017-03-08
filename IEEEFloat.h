//
// Created by Tanner on 3/1/2017.
//

#ifndef INTTOFLOAT_IEEEFLOAT_H
#define INTTOFLOAT_IEEEFLOAT_H

#include <vector>

// TODO: add documentation
class IEEEFloat {
public:

    /**
     * Given a number, returns a string containing that number's binary representation as an
     * IEEE floating point number.
     *
     * @param num is the number whose binary representation as an IEEE float will be found
     * @return num's binary representation as an IEEE float
     */
    static std::string toFloat(float const &num);

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

    /**
     * Given a number, computes and returns the sign bit for
     * if the number were to be represented in binary as an
     * IEEE float.
     *
     * @param num is the number whose sign bit for the above scenario will be found
     * @return the sign bit of num given the above scenario
     */
    static std::string computeSignBit(float const &num);
};


#endif //INTTOFLOAT_IEEEFLOAT_H
