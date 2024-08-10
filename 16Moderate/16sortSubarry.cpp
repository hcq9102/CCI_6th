// https://godbolt.org/z/q36n54vqG

#include <iostream>
#include <optional>
#include <algorithm> // for std::min and std::max
#include <bits/stdc++.h>
using namespace std;
/*
从左到右扫描：

找到第一个违反排序的地方，记为 m。这是因为在 m 之前的部分已经是有序的，但从 m 开始到数组结束的部分可能需要排序。
从右到左扫描：

找到第一个违反排序的地方，记为 n。这是因为在 n 之后的部分已经是有序的，但从 n 开始到数组结束的部分可能需要排序。
确定 m 和 n 的正确范围：

计算子数组 [m, n] 的最小值和最大值。
重新扫描数组，找到 m 和 n 的最小值和最大值在数组中应该插入的位置，以确保整个数组排序。

*/
std::pair<int, int> findUnsortedSubarray(const std::vector<int>& arr){
    int n = arr.size();
    if (n <= 1) {
        return {0, 0}; // The array is already sorted
    }

    // Step 1: Find the first and last index where the order is violated
    int left = 0;
    while (left < n - 1 && arr[left] <= arr[left + 1]) {
        ++left;
    }
    
    if (left == n - 1) {
        return {0, 0}; // The array is already sorted
    }

    int right = n - 1;
    while (right > 0 && arr[right] >= arr[right - 1]) {
        --right;
    }
    // Step 2: Find the minimum and maximum values in the subarray arr[left...right]
    int min_val = *std::min_element(arr.begin() + left, arr.begin() + right + 1);
    int max_val = *std::max_element(arr.begin() + left, arr.begin() + right + 1);

     // Step 3: Expand the range to include any numbers which are out of order
    while (left > 0 && arr[left - 1] > min_val) {
        --left;
    }
    while (right < n - 1 && arr[right + 1] < max_val) {
        ++right;
    }

   return {left, right};

}

int main() {
    std::vector<int> vec = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};

   auto result = findUnsortedSubarray(vec);
    std::cout << "Subarray to sort: from index " << result.first 
              << " to index " << result.second << std::endl;



    return 0;
}


