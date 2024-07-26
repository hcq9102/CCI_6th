//https://godbolt.org/z/qoa6oGeo3

#include<bits/stdc++.h>

using namespace std;

//helper func

void backtrack(vector<int> &num,vector<int> &subset, int start,vector<vector<int>> &res ){
    res.push_back(subset);
    
    for(int i = start; i< num.size(); i++){
        subset.push_back(num[i]);// 选择当前元素
        backtrack(num,subset, i+1, res); // 递归调用
        subset.pop_back();  // 撤销选择，准备下一个子集 
    }

}

vector<vector<int>> allSubset(vector<int> &num){
    
    vector<vector<int>> res;
    if(num.empty()) return res;

    vector<int> subset;
    backtrack(num, subset,0,res);
    return res;

}

// method2:
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
       
        //在原来的数组中不断追加下一个
        // o(n.2^n)
        res.push_back(vector<int>());

        for(int i = 0; i<nums.size();i++){
            int size = res.size(); // 当前子集数
            for(int j = 0; j<size;j++){

                vector<int> subset = res[j];// 拷贝所有子集
                subset.push_back(nums[i]); // 向拷贝的子集中加入当前数形成新的子集
                res.push_back(subset);  // 向res中加入新子集
            }
            
        }
        return res;
               
    }



int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << "All subsets:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}



