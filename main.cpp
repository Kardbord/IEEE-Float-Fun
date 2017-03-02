#include <iostream>
#include <cmath>
#include "IEEEFloat.h"

int main() {
    try{
        std::string test = IEEEFloat::toFloat(53, 0.214579);
        std::cout << test << std::endl;
    } catch (const char* msg){
        std::cerr << msg;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}