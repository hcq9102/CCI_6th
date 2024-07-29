//https://godbolt.org/z/TGnecWqW6

// #include<bits/stdc++.h>

// using namespace std;

// /*
// 将 n-1个圆盘借助 C 从 A 移至 B 。
// 将剩余 1个圆盘从 A 直接移至 C 。
// 将 𝑛−1个圆盘借助 A 从 B 移至 C 。


// 对于这两个子问题: 
// 𝑓(n-1)，可以通过相同的方式进行递归划分，直至达到最小子问题 f(1);
// where, f(1) =1;


// A ====>B =====>C
// f(n): f(n-1) + f(1)

//     put(n-1) plates from A to B with the help of C
//     put(1) plates from A to C directly;
//     put(n-1)plates from B to C with the help of A

// */

//-----------------------recirsion ----------------------//



// // 移动一个圆盘
// void move(vector<int> &src, vector<int> &tar) {
//     int pan = src.back();
//     src.pop_back(); // 移除源塔上的圆盘
//     tar.push_back(pan); // 将圆盘放到目标塔上
//     cout << "Move disk " << pan << " from source to target." << endl;
// }

// // 递归解决汉诺塔问题
// void dfs(vector<int> &src, vector<int> &buf, vector<int> &tar, int i) {
//     if (i == 1) {
//         move(src, tar);
//         return;
//     }

//     // 将 src 顶部 i-1 个圆盘借助 tar 移到 buf
//     dfs(src, tar, buf, i - 1);
//     // 将 src 剩余一个圆盘移到 tar
//     move(src, tar);
//     // 将 buf 顶部 i-1 个圆盘借助 src 移到 tar
//     dfs(buf, src, tar, i - 1);
// }

// void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C) {
//     int n = A.size();
//     // 将 A 顶部 n 个圆盘借助 B 移到 C
//     dfs( A, B, C,n);
// }

// // 打印塔的状态
// void printTower(const vector<int> &tower, char name) {
//     cout << "Tower " << name << ": ";
//     for (int disk : tower) {
//         cout << disk << " ";
//     }
//     cout << endl;
// }

// // 主函数
// int main() {
//     int n = 3; // 圆盘数量

//     // 初始化三个塔
//     vector<int> A, B, C;

//     // 塔 A 上放置 n 个圆盘，按大小顺序从大到小放置
//     for (int i = 1; i <=3; i++) {
//         A.push_back(i);
//     }

//     // 解决汉诺塔问题，将圆盘从 A 移到 C，使用 B 作为辅助塔
//     solveHanota(A, B, C);

//     // 打印最终塔的状态
//     printTower(A, 'A');
//     printTower(B, 'B');
//     printTower(C, 'C');

//     return 0;
// }

//------------------------------stack---------------//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 移动一个圆盘
void move(vector<int> &src, vector<int> &tar) {
    if (src.empty()) {
        cerr << "Error: Trying to move from an empty source stack." << endl;
        return;
    }
    int pan = src.back();
    src.pop_back();
    tar.push_back(pan);
    cout << "Move disk " << pan << " from source to target." << endl;
}

// 结构体保存汉诺塔的状态
struct State {
    vector<int> *src;  // 源塔
    vector<int> *buf;  // 辅助塔
    vector<int> *tar;  // 目标塔
    int n;            // 圆盘数量
};

// 使用堆栈解决汉诺塔问题
void solveHanota(int n, vector<int> &A, vector<int> &B, vector<int> &C) {
    stack<State> s;

    // 初始状态
    s.push({&A, &B, &C, n});
    
    while (!s.empty()) {
        State state = s.top();
        s.pop();

        if (state.n == 1) {
            if (!state.src->empty()) {
                move(*state.src, *state.tar);
            }
        } else {
            // 将 n-1 个圆盘从 src 移到 buf
            if (state.n > 1) {
                s.push({state.buf, state.src, state.tar, state.n - 1});
                s.push({state.src, state.tar, state.buf, 1});
                s.push({state.buf, state.src, state.tar, state.n - 1});
            }
        }
    }
}

// 打印塔的状态
void printTower(const vector<int> &tower, char name) {
    cout << "Tower " << name << ": ";
    if (tower.empty()) {
        cout << "Empty";
    } else {
        for (int disk : tower) {
            cout << disk << " ";
        }
    }
    cout << endl;
}

// 主函数
int main() {
    int n = 3; // 圆盘数量

    // 初始化三个塔
    vector<int> A, B, C;

    // 塔 A 上放置 n 个圆盘，按大小顺序从大到小放置
    for (int i = n; i >= 1; --i) {
        A.push_back(i);
    }

    // 解决汉诺塔问题，将圆盘从 A 移到 C，使用 B 作为辅助塔
    solveHanota(n, A, B, C);

    // 打印最终塔的状态
    printTower(A, 'A');
    printTower(B, 'B');
    printTower(C, 'C');

    return 0;
}

