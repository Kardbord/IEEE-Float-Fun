//
// Created by Tanner on 3/8/2017.
//

#ifndef INTTOFLOAT_BASETWONUMBER_H
#define INTTOFLOAT_BASETWONUMBER_H


class BaseTwoSciNumber {
public:
    BaseTwoSciNumber(float num);

    BaseTwoSciNumber(double num);

    BaseTwoSciNumber(int exp, int coef);

private:
    int exponent;
    int base = 2;
    double coefficient;

};


#endif //INTTOFLOAT_BASETWONUMBER_H
