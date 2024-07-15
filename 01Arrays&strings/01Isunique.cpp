// https://godbolt.org/z/jsPGsM3bo

#include <bits/stdc++.h>

using namespace std;

// method1 --- set
bool isUnique(string &str){
    set<char> myset;

    for(auto c : str){
        myset.insert(c);
    }

    return myset.size() == str.size();

}

bool isUnique_noDS(string &str){

    sort(str.begin(), str.end());

    for(int i = 1; i< str.size(); i++){
        if(str[i] ==str[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<string> tests = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : tests)
		{
			cout << word << string(": ") << boolalpha << isUnique(word) <<endl;
		}

        cout <<endl;

        for (auto word : tests)
		{
			cout << word << string(": ") << boolalpha << isUnique_noDS(word) <<endl;
		}


}

