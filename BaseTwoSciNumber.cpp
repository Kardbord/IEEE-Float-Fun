//
// Created by Tanner on 3/8/2017.
//

#include "BaseTwoSciNumber.h"
#include <cmath>

BaseTwoSciNumber::BaseTwoSciNumber(float const &num) : m_base(2) {
    toBaseTwoSci(num);
}

BaseTwoSciNumber::BaseTwoSciNumber(double const &num) : m_base(2) {
    toBaseTwoSci(num);
}

BaseTwoSciNumber::BaseTwoSciNumber(int const &exp, double const &coef) : m_base(2), m_exponent(exp),
                                                                         m_coefficient(coef) {}

void BaseTwoSciNumber::toBaseTwoSci(double const &num) {

    if (num < 2 && num > 1) {
        m_exponent = 0;
        m_coefficient = num;
        return;
    }

    double coef = num;
    int exponent;

    if (num > 2) {
        exponent = 1;
        for (exponent; coef > 2; ++exponent) {
            coef = num / std::pow(m_base, (double) exponent);
        }
    } else {
        exponent = -1;
        for (exponent; coef < 1; --exponent) { // TODO: fix bug where exponent ends up being off be one (one less than it should be)
            coef = num / std::pow(m_base, (double) exponent);
        }
    }

    m_coefficient = coef;
    m_exponent = exponent;
}

void BaseTwoSciNumber::toBaseTwoSci(float const &num) {
    if (num < 2 && num > 1) {
        m_exponent = 0;
        m_coefficient = num;
        return;
    }

    double coef = num;
    int exponent;

    if (num > 2) {
        exponent = 1;
        for (exponent; coef > 2; ++exponent) {
            coef = num / std::pow(m_base, (double) exponent);
        }
    } else {
        exponent = -1;
        for (exponent; coef < 1; --exponent) {
            coef = num / std::pow(m_base, (double) exponent);
        }
    }

    m_coefficient = coef;
    m_exponent = exponent;
}