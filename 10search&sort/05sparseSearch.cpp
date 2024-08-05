#include <vector>
#include <string>

class Solution {
public:
    int findString(std::vector<std::string>& words, std::string s) {
        int left = 0;
        int right = words.size() - 1;

        while (left <= right) {
            // 1. Locate the nearest non-empty string at the left and right boundaries
            while (left <= right && words[left].empty()) left++;
            while (left <= right && words[right].empty()) right--;

            // If boundaries are invalid, return -1
            if (left > right) return -1;

            // 2. Binary search for the target string
            int middle = left + (right - left) / 2;

            // If middle value is empty, linear scan to the right to find a non-empty string
            int temp = middle;
            while (temp <= right && words[temp].empty()) temp++;
            
            if (temp > right) { // If we run out of valid strings
                return -1; // Return -1 as no valid strings found
            }

            // Perform comparison with the found non-empty string
            if (words[temp] < s) {
                left = temp + 1;
            } else if (words[temp] > s) {
                right = middle - 1;
            } else {
                return temp;
            }
        }

        return -1;
    }
};


/*
定位到非空字符串：我们需要跳过空字符串，以确保 left 和 right 变量指向的是有效的字符串。
调整 middle：计算 middle 并确保其值不是空字符串。如果 middle 是空的，我们需要线性地向右查找，直到找到一个非空字符串或超出范围。
比较并更新边界：根据找到的非空字符串与目标字符串的比较结果，调整 left 和 right 变量，进行二分查找。
*/
