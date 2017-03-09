//
// Created by Tanner on 3/8/2017.
//

#ifndef INTTOFLOAT_BASETWONUMBER_H
#define INTTOFLOAT_BASETWONUMBER_H


class BaseTwoSciNumber {
public:
    BaseTwoSciNumber(float const &num);

    BaseTwoSciNumber(double const &num);

    BaseTwoSciNumber(int const &exp, double const &coef);

private:
    int m_exponent;
    const int M_BASE = 2;
    double m_coefficient;

    void toBaseTwoSci(double const &num);

    void toBaseTwoSci(float const &num);
};


#endif //INTTOFLOAT_BASETWONUMBER_H
