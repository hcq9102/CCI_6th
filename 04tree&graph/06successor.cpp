// https://godbolt.org/z/MPET74vEz

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// find the next node of p
TreeNode* Successor(TreeNode *root, TreeNode *p){
    if(root == nullptr) return nullptr;

    TreeNode *cur = root;
    TreeNode *ans = nullptr;

    while(cur){
        if(cur->val > p->val){
            ans = cur;
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
    return ans;
    
}


int main(){
    
   

    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->left->right->right = new TreeNode(8);
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);

    TreeNode* p = root1->right->right;
    TreeNode* ans =Successor(root1,p );

    if (ans) {
        cout << "p is: " << p->val << ", and its successor is: " << ans->val << endl;
    } else {
        cout << "p is: " << p->val << ", and it has no successor." << endl;
    }
   
    return 0;
}







