//https://godbolt.org/z/dWWGavYET

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// helper function
TreeNode* buildTree(const vector<int> &input, int start, int end){
    if(start>end) return nullptr;

    //1. find the middle for BST
    int mid = start + (end-start)/2;
    TreeNode* root = new TreeNode(input[mid]);

    root->left = buildTree(input, start,mid-1);
    root->right = buildTree(input, mid+1, end);

    return root;
}

// Function to create BST with minimal height from sorted array
TreeNode* createMinimalBST(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    return buildTree(nums, 0, nums.size() - 1);
}

// print inorder
void inOrderPrintTree(TreeNode * root){
    if(root == nullptr) return;
    inOrderPrintTree(root->left);
    cout << root->val <<" ";
    inOrderPrintTree(root->right);

} 

void preOrderPrintTree(TreeNode * root){
    if(root == nullptr) return;
    cout << root->val <<" ";
    inOrderPrintTree(root->left);
    inOrderPrintTree(root->right);

}

void postOrderPrintTree(TreeNode * root){
    if(root == nullptr) return;
    
    inOrderPrintTree(root->left);
    inOrderPrintTree(root->right);
    cout << root->val <<" ";
}

int main(){
    std::vector<int> input = {1,2,3,4,5,6,7};
    TreeNode* root = createMinimalBST(input);

    inOrderPrintTree(root);
    cout << endl;

    preOrderPrintTree(root);

    cout << endl;

    postOrderPrintTree(root);

    return 0;
}

