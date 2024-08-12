

#include <iostream>
#include <cassert>

int multiply(int a, int b) {
    int result = 0;
    int positiveB = (b > 0) ? b : -b;
    
    // Adding 'a', 'positiveB' times
    for (int i = 0; i < positiveB; ++i) {
        result += a;
    }
    
    // Adjust the result sign based on the signs of 'a' and 'b'
    if (b < 0) {
        result = -result;
    }
    
    return result;
}


int divide(int a, int b) {
    // Edge case for division by zero
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }

    int result = 0;
    int absoluteA = (a > 0) ? a : -a;
    int absoluteB = (b > 0) ? b : -b;
    
    // Subtract 'absoluteB' from 'absoluteA' until 'absoluteA' is less than 'absoluteB'
    while (absoluteA >= absoluteB) {
        absoluteA -= absoluteB;
        ++result;
    }
    
    // Adjust the result sign based on the signs of 'a' and 'b'
    if ((a < 0) ^ (b < 0)) {
        result = -result;
    }
    
    return result;
}
