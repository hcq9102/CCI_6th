// https://godbolt.org/z/WM8GG6xoe

#include <bits/stdc++.h>

using namespace std;
/*
1.need a bit Mask：
N:     10000000000, i=2, j=6
Mask:  11110000011

2.Mask can be done by：

Mask1: 11110000000
Mask2: 00000000011
Mask : Mask1 | Mask2
       11111000011

3.Mask1可以用-1 << j + 1来得到（-1到bit都是1），
Mask2可以用(1 << i) - 1得到。       
*/

// 函数：将 M 插入到 N 中，从第 i 位到第 j 位
int updateBits(int N, int M, int i, int j) {
    // // 所有位都是 1
    // int all_ones = ~0;
    // cout << "allones: " << all_ones<<endl;
    // // 创建掩码，清除第 j+1 位到 31 位
    // int left = all_ones << (j + 1);

    int left = -1<<(j+1);
    cout << std::bitset<32>(left)<<endl;
    // 创建掩码，清除第 i-1 位到 0 位
    int right = (1 << i) - 1;
    
    // 合并掩码
    int mask = left | right;
    cout << std::bitset<32>(mask)<<endl;
    // 清除 N 中第 i 到 j 位的位
    int n_cleared = N & mask;

    cout << std::bitset<32>(n_cleared)<<endl;
    
    // 将 M 左移 i 位对齐到正确的位置
    int m_shifted = M << i;
    cout << std::bitset<32>(m_shifted)<<endl;
    
    // 合并 M 和清除后的 N
    return n_cleared | m_shifted;
}

int main() {
    // 输入
    int N = 0b10000000000; // 1024 的二进制表示
    int M = 0b10011;       // 19 的二进制表示
    int i = 2;             // 目标位置的起始位
    int j = 6;             // 目标位置的结束位

    // 计算结果
    int result = updateBits(N, M, i, j);
    
    // 输出结果
    std::cout << "Result (binary): " << std::bitset<32>(result) << std::endl; // 输出 32 位的二进制结果
    std::cout << "Result (decimal): " << result << std::endl; // 输出十进制结果
    
    return 0;
}
