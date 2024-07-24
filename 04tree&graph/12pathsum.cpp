//https://godbolt.org/z/75oGTb44d

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// 访问每一个节点 node，检测以 node 为起始节点且向下延深的路径有多少种。我们递归遍历每一个节点的所有可能的路径，然后将这些路径数目加起来即为返回结果

int dfs(TreeNode* root, int sum){
    int cnt = 0;

    if(root == nullptr) return 0;
    if(root->val == sum){
        cnt++;
    }

    cnt += dfs(root->left, sum- root->val);
    cnt += dfs(root->right, sum- root->val);

    return cnt;
 }  

 // paths
 int countPathWithSum(TreeNode* root, int sum){
    if(root == nullptr) return 0;

    int res= 0;

    res = dfs(root, sum);
    res += countPathWithSum(root->left, sum);
    res += countPathWithSum(root->right, sum);
    return res;
 } 

 
    

int main() {
    
    
    // Hardcoded input sequence
    vector<int> values = {3, 2, 5, 1, 4};

    TreeNode* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }
    int sum  = 5;
    int res = countPathWithSum(root, sum);
    cout << "the total paths of tree with sum = "<<sum <<" are "<< res<<" paths" <<endl;

    return 0;
}
