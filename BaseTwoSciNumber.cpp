//
// Created by Tanner on 3/8/2017.
//

#include "BaseTwoSciNumber.h"
#include <cmath>

BaseTwoSciNumber::BaseTwoSciNumber(float const &num) : M_BASE(2) {
    toBaseTwoSci(num);
}

BaseTwoSciNumber::BaseTwoSciNumber(double const &num) : M_BASE(2) {
    toBaseTwoSci(num);
}

BaseTwoSciNumber::BaseTwoSciNumber(int const &exp, double const &coef) : M_BASE(2), m_exponent(exp),
                                                                         m_coefficient(coef) {}

void BaseTwoSciNumber::toBaseTwoSci(double const &num) {

    if (num < 2 && num >= 1) {
        m_exponent = 0;
        m_coefficient = num;
        return;
    }

    double coef = num;
    int exponent = 0;

    if (num > 2) {
        while (coef >= 2) {
            ++exponent;
            coef = num / std::pow(M_BASE, (double) exponent);
        }
    } else {
        while (coef < 1) {
            --exponent;
            coef = num / std::pow(M_BASE, (double) exponent);
        }
    }

    m_coefficient = coef;
    m_exponent = exponent;
}

void BaseTwoSciNumber::toBaseTwoSci(float const &num) {
    if (num < 2 && num >= 1) {
        m_exponent = 0;
        m_coefficient = num;
        return;
    }

    double coef = num;
    int exponent = 0;

    if (num > 2) {
        while (coef >= 2) {
            ++exponent;
            coef = num / std::pow(M_BASE, (double) exponent);
        }
    } else {
        while (coef < 1) {
            --exponent;
            coef = num / std::pow(M_BASE, (double) exponent);
        }
    }

    m_coefficient = coef;
    m_exponent = exponent;
}