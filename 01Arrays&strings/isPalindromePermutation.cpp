//https://godbolt.org/z/Mzcf5ja3r

#include <bits/stdc++.h>

using namespace std;

/*idea
* For a string to be pallindrome：
The function will count the occurrences of each character 
and then ensure that at most one character has an odd count.
* 
*/

bool isPermutationOfPallindrome(string &str){

    vector<int> freq(26,0);

    for(auto c: str){
        if(isalpha(c)){
            freq[tolower(c)]++;
        }
    }
    //check here that letter frequencies are all even or all even except one odd.
     
    int oddAppeared = 0;
    for(auto count : freq){
        if(count %2 !=0){
            oddAppeared++;
            if(oddAppeared >1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    std::string s = "Tact Coa";
    if (isPermutationOfPallindrome(s)) {
        std::cout << "\"" << s << "\" is a permutation of a palindrome." << std::endl;
    } else {
        std::cout << "\"" << s << "\" is not a permutation of a palindrome." << std::endl;
    }

    return 0;
    
}
