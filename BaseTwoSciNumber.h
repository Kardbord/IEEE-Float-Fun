//
// Created by Tanner on 3/8/2017.
//

#ifndef INTTOFLOAT_BASETWONUMBER_H
#define INTTOFLOAT_BASETWONUMBER_H

// TODO: add documentation
class BaseTwoSciNumber {
public:
    BaseTwoSciNumber(float const &num);

    BaseTwoSciNumber(double const &num);

    BaseTwoSciNumber(int const &exp, double const &coef);

    int getExponent() const { return m_exponent; }

    double getCoefficient() const { return m_coefficient; }

    int getBase() const { return M_BASE; }

private:
    int m_exponent;
    const int M_BASE = 2;
    double m_coefficient;

    void toBaseTwoSci(double const &number);

    void toBaseTwoSci(float const &number);
};


#endif //INTTOFLOAT_BASETWONUMBER_H
