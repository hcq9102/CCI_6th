//https://godbolt.org/z/eexeozdPn

#include <iostream>
#include <string>
using namespace std;

int conversion(int a, int b){
    // using xor to get c and count how many 1s in c
    int c = a^b;
    int cnt = 0;

    while(c){
        if(c&1){
            cnt++;
        }
        c = c>>1;
    }
    return cnt;

}


int main() {
    int a = 29; //(11101)
    int b = 15; //(01111)

    std::cout << "A is converted to B need to modify : " << conversion(a,b) <<" bits "<< std::endl;
    return 0;
}
