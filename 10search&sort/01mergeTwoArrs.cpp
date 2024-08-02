

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //不用swap，直接覆盖，影响不到valid sequenece
       // 从后开始填充
       int p1 = m-1;
       int p2 = n-1;

       int k = nums1.size() -1;

       while(p2>=0){
            while(p1>=0 && nums1[p1]>nums2[p2]){
                nums1[k--] = nums1[p1--];   
            }
            nums1[k--] = nums2[p2--];
            
       }    
    }
};
