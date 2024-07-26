//https://godbolt.org/z/W6qT68av6

#include <bits/stdc++.h>
using namespace std;
/*
dp[i] means,how many methods can reach the ith step.

dp function:
    dp[i] = dp[i-1] + dp[i-2]+dp[i-3];

*/
int tripleJump(int n){
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]+dp[i-3];
    }

    return dp[n];
}

int main(){

    int n = 6;

    cout << "tripleJump("<<n<<") = "<< tripleJump(n) <<endl;


    return 0;
}
