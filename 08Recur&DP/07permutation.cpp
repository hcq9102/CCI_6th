//https://godbolt.org/z/KzoW3Pdax

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
        if(!used[i]){
            path[depth]=nums[i];//update path                                                                                                                       
            used[i] = true;
            backtrack(nums, path,used,depth+1, res); //recurive call for next elem
            used[i] = false;// recover
        }

    }
}


vector<vector<int>> permute(vector<int> &nums){
    int n = nums.size();

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
            if(!used[i]){
                path.push_back(nums[i]);
                used[i] = true;
                backtrack2(nums, path,used,depth+1,res);

                used[i] = false;
                path.pop_back();
            }
        }
}

vector<vector<int>> permute2(vector<int> &nums){
    int n = nums.size();

    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(n,false);
  
    backtrack2(nums,path,used, 0,res);

    return res;

}

int main(){

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // method2

    cout << "method2 :" <<endl;

    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> result2 = permute2(nums2);
    
    for (const auto& perm : result2) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
