
//https://godbolt.org/z/WTG8b6zxf


#include <bits/stdc++.h>
using namespace std;
/*
1).
dp[i][j] means,how many methods can reach the grip(i,j) from (0,0).

due to robot can only move to Right and Down,
dp[i][j] can only from Left and Upper.

our goal is to get the value of dp[m-1][n-1];

2)
dp function:
    dp[i][j] = dp[i-1][j] +  dp[i][j-1];

3)
initial edge condition:
dp[0][j] = 1;   // because the upper bound dp[0][j] result can only from left,one path.
dp[i][0] =1;    //because the left bound dp[i][0] result can only from upper,one path.

第一行 (i = 0)
机器人只能从左到右移动：在第一行的任何位置 (0, j)，机器人只能从左边的邻居位置 (0, j-1) 移动过来。
路径唯一：从 (0, 0) 到 (0, j)，机器人必须一直向右移动，因此路径数量是 1。
第一列 (j = 0)
机器人只能从上到下移动：在第一列的任何位置 (i, 0)，机器人只能从上边的邻居位置 (i-1, 0) 移动过来。
路径唯一：从 (0, 0) 到 (i, 0)，机器人必须一直向下移动，因此路径数量是 1。
*/

// assume g[i][j] =1 is offlimit. remaining are all 0s.
/*
ie.:

0 0 0 0
0 1 0 0
0 0 0 0

*/

int robotGrid(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));

     // 初始化起点
    if (grid[0][0] == 0) {
        dp[0][0] = 1;
    }

    // 填充第一行
    for (int j = 1; j < m; ++j) {
        if (grid[0][j] == 0) {
            dp[0][j] = dp[0][j-1];
        }
    }

    // 填充第一列
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == 0) {
            dp[i][0] = dp[i-1][0];
        }
    }
    // fill remainings
    for(int i = 1; i<m; i++){
        for(int j = 1; j<n; j++){
            // only update the valid grid
            // if its offlimits，still be 0
            if(grid[i][j] == 0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            
        }
    }

    return dp[m-1][n-1];
}

int main(){

    //0 means can pass，1 represents offlimits
    vector<vector<int>> grid0 = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    int result0 = robotGrid(grid0);
    if(result0){
        cout << "Total unique paths in the grid: " << result0 << endl;
    }else{
        cout << "Robot cannot reach the end: " << endl;
    }

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    int result = robotGrid(grid);
    if(result){
        cout << "Total unique paths in the grid: " << result << endl;
    }else{
        cout << "Robot cannot reach the end: " << endl;
    }
    

    return 0;
}
