#include <iostream>
#include <cmath>
#include "IEEEFloat.h"

int main() {
    try{
        std::string test = IEEEFloat::toFloat(0, 0.214572);
        std::cout << test << std::endl;
    } catch (const char* msg){
        std::cerr << msg;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}