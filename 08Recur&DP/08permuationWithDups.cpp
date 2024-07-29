// https://godbolt.org/z/Eo18K15E6

#include<bits/stdc++.h>

using namespace std;

//--------------------------------- method1, backtrcak----------------------------------//
void backtrack(vector<int> &nums, vector<int> &path,vector<bool> &used, int depth, vector<vector<int>> & res){
    if(depth == nums.size()){
        res.push_back(path);
        return;
    }

    // make choice
    for(int i = 0; i< nums.size(); i++){
            //其次，我们已经选择过的不需要再放进去了
            if(used[i]==true) continue;
            //接下来，如果当前节点与他的前一个节点一样，并其他的前一个节点已经被遍历过了，那我们也就不需要了。
            if(i>0 && nums[i] ==nums[i-1] && used[i-1]) break;  
            
            path[depth]=nums[i];//update path                                                                                                                       
            used[i] = true;
            backtrack(nums, path,used,depth+1, res); //recurive call for next elem
            used[i] = false;// recover
        

    }
}


vector<vector<int>> permute(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());

    vector<vector<int>> res;
    vector<int> path(n,0);
    vector<bool> used(n,false);
    backtrack(nums,path,used, 0,res);

    return res;

}


//--------------------------------- method2, backtrcak----------------------------------//

void backtrack2(vector<int> &nums, vector<int> &path,vector<bool> &used, int depth, vector<vector<int>> & res){
    if(depth == nums.size()){
        res.push_back(path);
        return;
    }

    for(int i = 0; i<nums.size(); i++){
            if(used[i] || (i>0 && !used[i-1] && nums[i] == nums[i-1])){//用过了
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtrack2(nums, path,used,depth+1,res);

            used[i] = false;
            path.pop_back();
            
        }
}

vector<vector<int>> permute2(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());

    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(n,false);
  
    backtrack2(nums,path,used, 0,res);

    return res;

}

int main(){

    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = permute(nums);
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // method2

    cout << "method2 :" <<endl;

    vector<int> nums2 = {1, 1, 2};
    vector<vector<int>> result2 = permute2(nums2);
    
    for (const auto& perm : result2) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
