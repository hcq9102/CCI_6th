//https://godbolt.org/z/bcdTGo5K9

#include <bits/stdc++.h>

using namespace std;
// method1 using rotate() algorithm
bool isRotate(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    if(n !=m) return false;

    for(int i = 0; i<n; i++){
        rotate(s1.begin(), s1.begin()+i, s1.end());
        // s1, after rotation
        if(s1 == s2 ){
            return true;
        }
    }
    return false;
}

// method2 using substring, string::find()
bool isRotation( std::string &s1, std::string &s2 ) {
    int n = s1.size();
    int m = s2.size();

    if(n ==0 || n !=m) return false;
     // s2 must be substring of s1+s1 if s1 and s2 can be rotation 
    string concat = s1+s1;

    if(concat.find(s2) != std::string::npos){
        return true;
    }else{
        return false;
    }

}


int main() {
    string test = "waterbottle";
    string test2 = "erbottlewat";

    if(isRotate(test,test2)){
        cout << "Is string rotation"<<endl;
    }else{
        cout << "Is NOT string rotation"<<endl;
    }

    // test isRotation
    cout << "Test another way rotation !"<<endl;
    if(isRotation(test,test2)){
        cout << "Is string rotation"<<endl;
    }else{
        cout << "Is NOT string rotation"<<endl;
    }

    return 0;
}
