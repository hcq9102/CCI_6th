// https://godbolt.org/z/re85hYGjq

#include<bits/stdc++.h>

using namespace std;

/*
创建一个 dp 数组，dp[i] 表示用不同面额的硬币表示 i 美分的不同方式的数量。

dp[0] 初始化为 1，表示表示 0 美分只有一种方式：不使用任何硬币。
*/
int countWaysToMakeChange(int n) {
    // 硬币面额
    vector<int> coins = {25, 10, 5, 1};
    vector<int> dp(n + 1, 0);
    
    // 初始化，表示有一种方式来表示 0 美分，即不使用任何硬币
    dp[0] = 1;

    // 遍历每种硬币面额
    for (int coin : coins) {
        for (int i = coin; i <= n; ++i) {
            dp[i] =dp[i] + dp[i - coin];
        }
    }

    return dp[n];
}


int main() {
    int n = 30;
    
    cout << "Number of ways to make change for " << n << " cents: " << countWaysToMakeChange(n) << endl;

    return 0;
}
