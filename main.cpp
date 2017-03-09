#include <iostream>
#include <cmath>
#include "IEEEFloat.h"
#include "BaseTwoSciNumber.h"

int main() {

    try{
        std::string test = IEEEFloat::toFloat(0.085);
        std::cout << test << std::endl;
    } catch (const char* msg){
        std::cerr << msg;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}