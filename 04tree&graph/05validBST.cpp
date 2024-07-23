// https://godbolt.org/z/45do8xbaa

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// recursive: focus on each node, on what's the proper thing it should do, after then, the recursive function will take over all.
bool helper(TreeNode *root, int min, int max){
    if(root == nullptr) return true;
    if((min >= root->val )|| (max <= root->val )){
        return false;
    }

    return helper(root->left, min, root->val) && helper(root->right,root->val, max); 
}

bool IsBST(TreeNode *root){
    return helper(root, INT_MIN, INT_MAX);
}


int main(){
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    if(IsBST(root)){
        cout <<"Tree is Binary search tree!"<<endl;
    }else{
        cout <<"Tree is NOT Binary search tree!"<<endl;

    }

    cout <<"Another case: "<<endl;

    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->left->right->right = new TreeNode(8);
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);


    if(IsBST(root1)){
        cout <<"Tree is Binary search tree!"<<endl;
    }else{
        cout <<"Tree is NOT Binary search tree!"<<endl;

    }
   
    return 0;
}



