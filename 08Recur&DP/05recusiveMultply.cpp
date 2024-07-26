//https://godbolt.org/z/6vE7enb4c

#include<bits/stdc++.h>

using namespace std;

// method1
int multplyRecursive(int a, int b){
    if(a>b){
        int t = a;
        a = b;
        b =t;
    }
    int res = 0;

    while(a){
        res+=b;
        a--;
    }

    return res;
}

// optimize: // method2
/*
在数学中，乘法可以看作是重复加法的扩展。例如：

如果 b 是一个偶数，我们可以通过以下方式来减少加法的次数：
a×b=a×(b/2)×2
*/

int recursiveMultiply2(int a, int b) {
    // 基本情况：b为0时，结果为0
    if (b == 0) {
        return 0;
    }
    
    // 递归情况：b为奇数时，返回 a + recursiveMultiply(a, b - 1)
    if (b % 2 == 1) {
        return a + recursiveMultiply2(a, b - 1);
    }
    
    // 递归情况：b为偶数时，使用位移操作简化计算
    int halfProduct = recursiveMultiply2(a, b >> 1); // b / 2
    return halfProduct + halfProduct; // 等同于 a * b
}

int main(){
    int a = 20;
    int b = 30;

    cout << a<<"*"<<b <<" = "<< multplyRecursive(a,b)<<endl;

    cout << a<<"*"<<b <<" = "<< recursiveMultiply2(a,b)<<endl;
    return 0;
}
