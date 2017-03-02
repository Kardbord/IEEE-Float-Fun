#include <iostream>
#include <cmath>
#include "IEEEFloat.h"

int main() {
    std::string test = IEEEFloat::toFloat(0, 0.214579);
    std::cout << test << std::endl;
    return EXIT_SUCCESS;
}