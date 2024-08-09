// https://godbolt.org/z/qrb4Tf4rv

#include <iostream>
#include <optional>
#include <algorithm> // for std::min and std::max
#include <bits/stdc++.h>
using namespace std;

/*
16.19 池塘大小（Pond Sizes）:你有一个整数矩阵，代表一块土地，其中该位置的值代表海拔高度。0 值表示水。池塘是横、竖或对角线相连的水域。池塘的大小是相连的水格（water cells）总数。编写一种方法来计算矩阵中所有池塘的大小。

EXAMPLE

Input:
0 2 1 0
0 1 0 1
1 1 0 1
0 1 0 1
Output: 2, 4, 1 (in any order)
*/
void dfs(vector<vector<int>>& grid, int i, int j,int& size){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()||grid[i][j] != 0){
        return;
    }

    grid[i][j] = -1;

    size++;

    dfs(grid, i+1,j, size);
    dfs(grid, i-1,j,size);
    dfs(grid, i,j+1,size);
    dfs(grid, i,j-1,size);
    dfs(grid, i-1,j-1,size);
    dfs(grid, i+1,j+1,size);
    dfs(grid, i-1,j+1,size);
    dfs(grid, i+1,j-1,size);

}

vector<int> pondSize(vector<vector<int>>& grid){

    vector<int> res;
    
    for(int i = 0; i< grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[i][j] == 0){
                int size = 0;
                dfs(grid, i,j,size);
                if(size>0){
                    res.push_back(size);
                }
            }
        }
        
    }

    return res;
   
    
}


int main() {
    // 示例矩阵
    vector<vector<int>> matrix = {
        {0, 2, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1}
    };
    
    // 计算池塘大小
    vector<int> sizes = pondSize(matrix);
    
    // 输出结果
    for (int size : sizes) {
        cout << size << " ";
    }
    cout << endl;
    
    return 0;
}

