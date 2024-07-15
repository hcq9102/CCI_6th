//https://godbolt.org/z/fceEE37oz
#include <bits/stdc++.h>

using namespace std;

string strCompression(string &s){
    
    int n = s.size();
    if(n == 0 || n<=2) return s;
    string res ="";
    int cnt = 1;
    int i = 1;
    res += s[0];
    while(i <n){
        while(i<n && s[i] == s[i-1]){
            cnt++;
            i++;
        }
        res += to_string(cnt);

        // start new compression
        res += s[i];
        cnt = 1;
        i++;
    }

    return res.size()>=n ? s:res;
}

int main(){

    std::string s1 = "aabcccccaaa";
    std::cout << "string \"" << s1 << "\" strCompression  is\"" <<  strCompression(s1) << std::endl; // true
    
    return 0;
    
}
