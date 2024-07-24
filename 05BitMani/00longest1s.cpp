//https://godbolt.org/z/6n64zvPE5

#include <bits/stdc++.h>

using namespace std;

unsigned int longest1s(unsigned int n){
    unsigned cur_len = 0;
    unsigned max_len = 0;

    while(n>0){
        if(n&1){
            cur_len++;
            max_len = std::max(max_len, cur_len);
        }else{
            cur_len = 0;
        }
        n = n>>1; // update n
    }

    return max_len;
}

int main(){
    unsigned int n = 0b1111111111011101111;  // 例如输入的二进制数
    std::cout << "Longest sequence of 1s: " << longest1s(n) << std::endl;
    return 0;
}
