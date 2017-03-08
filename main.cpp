#include <iostream>
#include <cmath>
#include "IEEEFloat.h"
#include "BaseTwoSciNumber.h"

int main() {

    BaseTwoSciNumber test(2, 1.36);

    BaseTwoSciNumber test1(0.085);

    /*try{
        std::string test = IEEEFloat::toFloat(53, 0.214579);
        std::cout << test << std::endl;
    } catch (const char* msg){
        std::cerr << msg;
        return EXIT_FAILURE;
    }*/
    return EXIT_SUCCESS;
}