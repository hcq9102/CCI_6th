// leetcode 702

class Solution {
public:
    int search(const Listy& listy, int target) {
        int left = 0, right = 20000;
        while (left <= right) {
            int mid = left + right >> 1;
            if (listy.elementAt(mid) == target) {
                return mid;
            } else if(listy.elementAt(mid) > target) {
                right = mid - 1;
            }else{
                left = mid+1;
            }
        }
        return -1
    }
};
