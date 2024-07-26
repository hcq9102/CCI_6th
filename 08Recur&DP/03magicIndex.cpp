//https://godbolt.org/z/zKn4rzWPn


// #include <iostream>
// #include <vector>

// using namespace std;

// int findMagicIndex(const vector<int>& A, int left, int right) {
//     if (left > right) {
//         return -1; // 没有找到魔法索引
//     }

//     int mid = left + (right - left) / 2;

//     if (A[mid] == mid) {
//         return mid; // 找到魔法索引
//     } else if (A[mid] > mid) {
//         // 魔法索引可能在左侧子数组中
//         return findMagicIndex(A, left, mid - 1);
//     } else {
//         // 魔法索引可能在右侧子数组中
//         return findMagicIndex(A, mid + 1, right);
//     }
// }

// int main() {
//     vector<int> A = {-1, 0, 1, 3, 4, 5, 7, 8};

//     int index = findMagicIndex(A, 0, A.size() - 1);
//     if (index != -1) {
//         cout << "Magic index is: " << index << endl;
//     } else {
//         cout << "No magic index found." << endl;
//     }

//     return 0;
// }


// -------------follow up, values are not distinct-----------------------

#include <iostream>
#include <vector>

using namespace std;

void findMagicIndices(const vector<int>& A, int left, int right, vector<int>& result) {
    if (left > right) {
        return;
    }

    int mid = left + (right - left) / 2;

    if (A[mid] == mid) {
        result.push_back(mid);
        // 在找到一个魔法索引后，继续搜索左侧和右侧区域
        // 这里的逻辑保证我们不会遗漏任何魔法索引
        findMagicIndices(A, left, mid - 1, result); // 继续在左侧搜索
        findMagicIndices(A, mid + 1, right, result); // 继续在右侧搜索
    } else if (A[mid] > mid) {
        // 如果 A[mid] > mid，魔法索引可能在左侧区域
        findMagicIndices(A, left, mid - 1, result);
    } else {
        // 如果 A[mid] < mid，魔法索引可能在右侧区域
        findMagicIndices(A, mid + 1, right, result);
    }
}

int main() {
    vector<int> A = {-1, 0, 1, 3, 4, 5, 7, 8};
    vector<int> result;

    findMagicIndices(A, 0, A.size() - 1, result);

    if (!result.empty()) {
        cout << "Magic indices are: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "No magic index found." << endl;
    }

    return 0;
}
