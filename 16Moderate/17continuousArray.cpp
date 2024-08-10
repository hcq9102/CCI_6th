// https://leetcode.cn/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;

        int presum = nums[0];
        int res = nums[0];

        for(int i = 1; i< nums.size(); i++){
            presum =max(nums[i]+presum , nums[i]);

            res = max(res, presum);

        }
        return res;
        
    }
};
