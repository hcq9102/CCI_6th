// https://godbolt.org/z/xa3h31zda

// 3 methods
#include <bits/stdc++.h>

using namespace std;

bool isPermutation(string &str1, string &str2){
    if(str1.size() != str2.size()) return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

bool isPermutation_map(string &str1, string &str2){
    if(str1.size() != str2.size()) return false;
    unordered_map<char, int> map;

    for(auto c: str1){
        map[c]++;
    }

    for(auto ch : str2){
        if(map.count(ch)==0){
            return false;
        }
        map[ch]--;
    }
    return true;  
}

bool isPermutation_noDS(string &str1, string &str2){
    if(str1.size() != str2.size()) return false;
    vector<int> count(256,0);

    for(auto c: str1){
        count[c]++;
    }
    for(auto ch : str2){
        if(count[ch]<0){
            return false;
        }
        count[ch]--;
    }
    return true;  
}



int main(){

    string str1 = "abcde";
    string str2 = "adcef";

    auto res = isPermutation(str1, str2);
    if(res == 1){
        cout << "str1, str2 are Permutation: "<<endl;
    }else{
        cout << "str1, str2 are NOT Permutation: " <<endl;
    }

    string str3 = "hello";
    string str4 = "llohe";

    auto res2 = isPermutation_map(str3, str4);
    if(res2 == 1){
        cout << "str1, str2 are Permutation: "<<endl;
    }else{
        cout << "str1, str2 are NOT Permutation: " <<endl;
    }

    string str5 = "ThisTest";
    string str6 = "TestThat";

    auto res3 = isPermutation_noDS(str5, str6);
    if(res3 == 1){
        cout << "str1, str2 are Permutation: "<<endl;
    }else{
        cout << "str1, str2 are NOT Permutation: " <<endl;
    }

    return 0;


}



