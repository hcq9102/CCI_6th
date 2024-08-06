//https://godbolt.org/z/4fq3enP3b

#include <bits/stdc++.h>
using namespace std;

void swapper(int &a, int &b){

    a = a - b;
    b = b+a; // b + (a-b) = a

    a = b-a; // a -(a-b) = b
}

// method 2
void swapper1(int &a, int &b){
// 这种方法的核心在于 XOR 运算的性质：
// x ^ x = 0：相同的数异或为 0。
// x ^ 0 = x：任何数与 0 异或为其本身。
    a = a ^ b;  // Step 1: a becomes a ^ b
    b = a ^ b;  // Step 2: b becomes (a ^ b) ^ b which is a
    a = a ^ b;  // Step 3: a becomes (a ^ b) ^ a which is b
}

int main() {
    int a = 9;
    int b = 4;

    cout << "origin a,b :" << "a = "<<a << "; b = "<<b<<endl;

    swapper1(a,b);

    cout << "swap   a,b :" << "a = "<<a << "; b = "<<b<<endl;

    
    return 0;
}
