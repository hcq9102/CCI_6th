//https://godbolt.org/z/z7nnqYdd9

#include<bits/stdc++.h>

using namespace std;

/*
* @param left   左括号已经用了几个
* @param right  右括号已经用了几个
*/
void dfs(int n, string curstr, int left, int right, vector<string> &res){
    if(left == n && right ==n){
        res.push_back(curstr);
        return;
    }

    //pruning
    if(left<right){
        return;
    }

    if(left <n){
        dfs(n, curstr+"{", left+1, right, res);
    }

    if(right <n){
        dfs(n, curstr+"}", left, right+1, res);
    }

}

vector<string> parenthese(int n){
    vector<string> res;
    string curstr="";
    dfs(n,curstr, 0,0,res);
    return res;
}

int main(){
    int n = 3;

    vector<string> res = parenthese(n);
    for(auto& str: res){
        cout << str <<endl;
    }

    return 0;
}

