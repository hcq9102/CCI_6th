// https://godbolt.org/z/5jsWxEnoM

#include<bits/stdc++.h>

using namespace std;

// dp[i] means the maximum height at ith box
// similar the longest asc subsequence
// compare itself and the longest asc subsequence
/*
思路：每个箱子有三个维度，按照宽进行排序后降为二维，即可用最长上升子序列的思路来解。
状态方程：
dp[i] 表示以第 i 个箱子为最底端箱子时，箱堆的最大高度。
dp[i] = Max( dp[j] ) + box[i][2] 其中 0 <= j < i ,且 i 的三维都要比 j 大

*/


bool compareBox(vector<int> &a, vector<int> &b){
    return a[0]>b[0] && a[1]>b[1]&&a[2]>b[2];
}

int maxHeightSolve(vector<vector<int>>& box){
    int n = box.size();
    // sort by width
    sort(box.begin(), box.end(), [](const vector<int> &a, const vector<int> &b ){
                                        return a[0]<b[0];

    });

    vector<int> dp(n,0);
    //initialize
    for(int i = 0; i<n; i++){
        dp[i] = box[i][2];
    }

    int maxHeight = 0;

    for(int i = 0; i< n; i++){
        for(int j = 0; j<i; j++){
            if(box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]){
                dp[i] = max(box[i][2]+dp[j], dp[i]);
            }
        }
        maxHeight = max(maxHeight, dp[i]);
    }
    return maxHeight;

}

int main() {
    // 示例数据：每个箱子由 [宽, 深, 高] 组成
    vector<vector<int>> boxes = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    cout << "Maximum height of stacked boxes: " << maxHeightSolve(boxes) << endl;
    

    // test2
    vector<vector<int>> boxes2= {{1, 1, 1}, {2, 3, 4}, {2, 6, 7},{3, 4, 5}};
    cout << "Maximum height of stacked boxes2: " << maxHeightSolve(boxes2) << endl;
    return 0;
}
