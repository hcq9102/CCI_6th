#include <iostream>
#include <cmath> // For abs()

int findMax(int a, int b) {
    return (a + b + std::abs(a - b)) / 2;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    std::cout << "The maximum of " << num1 << " and " << num2 << " is " << findMax(num1, num2) << std::endl;
    return 0;
}
