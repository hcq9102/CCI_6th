// https://godbolt.org/z/c4PKEKTes

#include <iostream>
#include <bitset>

// 找到下一个较小的数
int getNext(int n) {
    if (n <= 0) return -1;

    int c = n;
    int c0 = 0;
    int c1 = 0;

    while (((c & 1) == 0) && (c != 0)) {
        c0++;
        c >>= 1;
    }

    while ((c & 1) == 1) {
        c1++;
        c >>= 1;
    }

    if (c0 + c1 == 31 || c0 + c1 == 0) return -1;

    int pos = c0 + c1;

    n |= (1 << pos);
    n &= ~((1 << pos) - 1);
    n |= (1 << (c1 - 1)) - 1;

    return n;
}

// 找到上一个较大的数
int getPrev(int n) {
    if (n <= 0) return -1;

    int temp = n;
    int c0 = 0;
    int c1 = 0;

    while ((temp & 1) == 1) {
        c1++;
        temp >>= 1;
    }

    if (temp == 0) return -1;

    while (((temp & 1) == 0) && (temp != 0)) {
        c0++;
        temp >>= 1;
    }

    int p = c0 + c1;

    n &= ((~0) << (p + 1));
    int mask = (1 << (c1 + 1)) - 1;
    n |= mask << (c0 - 1);

    return n;
}

int main() {
    int n = 13948; // 示例数字（二进制：11011001111100）

    int next = getNext(n);
    int prev = getPrev(n);

    std::cout << "具有相同数量1的下一个较小的数: " << next << " (" << std::bitset<32>(next) << ")" << std::endl;
    std::cout << "具有相同数量1的上一个较大的数: " << prev << " (" << std::bitset<32>(prev) << ")" << std::endl;

    return 0;
}

/*
getNext 函数
找到第一个右边的非尾随零：通过右移和统计 c0、c1 来找到第一个 0 但它右边有 1 的位置。
翻转这个位置上的位：将这个位置的 0 翻转为 1。
设置右边的位：重置右边所有位，然后将 c1-1 个 1 放在右边。
getPrev 函数
找到第一个右边的非尾随的一：通过右移和统计 c0、c1 来找到第一个 1 但它右边有 0 的位置。
翻转这个位置上的位：将这个位置的 1 翻转为 0。
设置右边的位：重置右边所有位，然后将 c1+1 个 1 放在右边。
*/
