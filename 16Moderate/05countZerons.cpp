

#include <iostream>

int countTrailingZeros(int n) {
    int count = 0;
    int powerOfFive = 5;
    
    while (n / powerOfFive > 0) {
        count += n / powerOfFive;
        powerOfFive *= 5;
    }
    
    return count;
}

int main() {
    int number = 100; // Example number
    std::cout << "Number of trailing zeros in " << number << "! is " << countTrailingZeros(number) << std::endl;
    return 0;
}


、、方法
1. 计算因子 5 的数量：要确定 
𝑛! 中尾随零的数量，我们需要计算在从 1 到 n 的所有数中因子 5 的总数。

2. 5 的倍数：每个 5 的倍数都会贡献至少一个 5。

3. 更高次方的 5：对于 25（即 5^2）的倍数，这些数每个都会额外贡献一个 5。同样，对于 125（即 
5^3）的倍数，每个额外贡献另一个 5，以此类推。
