// https://godbolt.org/z/bTvKr8xfM

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<vector<int>> findPairs(vector<int>& nums, int target) {
    unordered_map<int, int> cnt; // 存储每个数的出现次数
    vector<vector<int>> result;    // 存储结果对

    for(int x : nums){
        int y = target - x;
        if(cnt[y]){
            cnt[y]--; // avoid duplicate
            result.push_back({x,y});
        }else{
            cnt[x]++;
        }
    }
    return result;

}

int main() {
    vector<int> nums1 = {5, 6, 5};
    int target1 = 11;
    vector<vector<int>> result1 = findPairs(nums1, target1);
    for (const auto& pair : result1) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    vector<int> nums2 = {5, 6, 5, 6};
    int target2 = 11;
    vector<vector<int>> result2 = findPairs(nums2, target2);
    for (const auto& pair : result2) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}
