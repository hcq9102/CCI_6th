class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                return mid;
            }
            //左边上升的元素多，即pivot在右侧
            if(nums[left]<=nums[mid]){ 
                //再判断在mid的左边或右边找target。
                //左
                if(nums[left] <=target &&target <nums[mid]){
                    right = mid;
                }else{
                    left = mid+1;
                }

            }else{//pivot在左半侧,右边上升的元素多
                //再判断在mid的左边或右边找target。
                //右
                if(nums[mid] < target && target <=nums[right]){
                    left = mid +1;
                }else{
                    right = mid;
                }

            }
        }
        
    return -1; 
    }
};
