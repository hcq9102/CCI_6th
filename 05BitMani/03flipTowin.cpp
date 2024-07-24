//https://godbolt.org/z/c4PKEKTes

#include <iostream>
#include <string>
using namespace std;

int flipToWin(int num){
    if(~num==0) return 32;

    int curLen = 0;
    int preLen = 0;

    int maxLen= 0;

    while(num>0){
        if(num&1){
            // current is 1
            curLen++;
        }else{
            //current is 0
            /// if next pos is 0 too, then we cannot connect
            /// if next pos is 1 , then we can connect
            preLen = (num&2)==0? 0 : curLen;
            curLen = 0; // meet 0, update curlen to 0
        }
        maxLen = max(preLen + curLen +1 , maxLen); // +1 means flip this 0
        num = num>>1;
    }
    return maxLen;
}


int main() {
    int n = 1775; // Example number (binary 11011101111)
    std::cout << "Longest sequence of 1s after flipping one bit: " << flipToWin(n) << std::endl;
    return 0;
}
