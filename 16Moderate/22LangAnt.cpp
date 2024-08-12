

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> printKMoves(int K) {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        int dirs[5] = {0, 1, 0, -1, 0};
        string d = "RDLU";
        int x = 0, y = 0, p = 0;
        set<pair<int, int>> black;
        while (K--) {
            auto t = make_pair(x, y);
            if (black.count(t)) {
                black.erase(t);
                p = (p + 3) % 4;
            } else {
                black.insert(t);
                p = (p + 1) % 4;
            }
            x += dirs[p];
            y += dirs[p + 1];
            x1 = min(x1, x);
            y1 = min(y1, y);
            x2 = max(x2, x);
            y2 = max(y2, y);
        }
        int m = x2 - x1 + 1, n = y2 - y1 + 1;
        vector<string> g(m, string(n, '_'));
        for (auto& [i, j] : black) {
            g[i - x1][j - y1] = 'X';
        }
        g[x - x1][y - y1] = d[p];
        return g;
    }
};

int main() {
    Solution sol;
    int K=2;
   
    vector<string> result = sol.printKMoves(K);
    for (const auto& row : result) {
        cout << row << endl;
    }
    return 0;
}
/*
初始化：

x1, y1 和 x2, y2 用于跟踪网格的边界。
dirs 数组定义了蚂蚁的四个运动方向：右（0,1），下（1,0），左（0,-1），上（-1,0）。
d 字符串表示蚂蚁的方向：右（R），下（D），左（L），上（U）。
black 是一个 set，用来存储黑色方格的坐标。
x 和 y 是蚂蚁的当前位置，p 是当前的方向索引。

模拟运动：

使用 while (K--) 循环执行 K 次运动。
在每一步中，如果当前方格是黑色，则将其改为白色，并左转（更新方向索引 p）；如果当前方格是白色，则将其改为黑色，并右转（更新方向索引 p）。
根据当前方向更新蚂蚁的位置，并更新网格边界。
生成结果：

根据计算出的网格边界，创建一个适当大小的网格 g，用 '_' 填充。
将黑色方格设置为 'X'。
最后，将蚂蚁的最终方向标记在其所在位置
*/
