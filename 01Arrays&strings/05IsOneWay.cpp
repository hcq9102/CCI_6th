// https://godbolt.org/z/MGqvsb44E

#include <bits/stdc++.h>

using namespace std;

bool isOneWay(string str1, string str2){
    // insert, remove, replace(uneditted)
    int l1 = str1.size();
    int l2 = str2.size();

    if(abs(l1 - l2)>1){
        return false;
    }

    string shorter = l1 <l2? str1 : str2;
    string longer = l1>l2? str2 : str1;

    int idx1 = 0;
    int idx2 = 0;
    
    bool foundDif = false;
    while(idx1 < shorter.size() && idx2<longer.size()){
        if(shorter[idx1] != longer[idx2]){
            if(foundDif){
                return false;
            }

            foundDif = true;
        
        // If lengths are different, move the longer string index only
        // here, to simulate the delete or remove operations
            if(l1 != l2){
                idx2++;
                continue;
            }
        }

        idx1++;
        idx2++;
    }
    return true;
}

int main(){

    std::string s1 = "pale";
    std::string s2 = "ple";
    std::string s3 = "pales";
    std::string s4 = "bale";
    std::string s5 = "bake";

    std::cout << std::boolalpha; // Print boolean values as true/false

    std::cout << "Is \"" << s1 << "\" one edit away from \"" << s2 << "\"? " << isOneWay(s1, s2) << std::endl; // true
    std::cout << "Is \"" << s1 << "\" one edit away from \"" << s3 << "\"? " << isOneWay(s1, s3) << std::endl; // true
    std::cout << "Is \"" << s1 << "\" one edit away from \"" << s4 << "\"? " << isOneWay(s1, s4) << std::endl; // true
    std::cout << "Is \"" << s1 << "\" one edit away from \"" << s5 << "\"? " << isOneWay(s1, s5) << std::endl; // false
    

    return 0;
    
}
