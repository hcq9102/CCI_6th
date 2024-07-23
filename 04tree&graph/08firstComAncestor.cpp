//https://godbolt.org/z/44bPYz7vK

// similar: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


/*
first common ancestor:(NOT BST)

1. p1, and p2 on different child subtree, return root

2. p1, and p2 on same child subtree:

    p1, p2 are not parent-child relationship: first parent of both.
    p1, p2 are parent-child relationship: return parent.

递归的找出左右子树的LCA，再判断两者
1. 都不为空，说明p,q分别在左右子树。
2. 一个为空，说明p,q都在另外一个子树，返回另一个子树的LCA。

*/

TreeNode* firstAncestor(TreeNode* root, TreeNode *p1, TreeNode *p2){
    
    if(p1 == root || p2 ==root) return root;

    if(root !=nullptr){
        TreeNode* leftLCA = firstAncestor(root->left, p1, p2);
        TreeNode* rightLCA = firstAncestor(root->right, p1, p2);
        if(leftLCA !=nullptr &&  rightLCA !=nullptr){
            return root;
        }else if(leftLCA ==nullptr ){// p1, p2 all on right
            return rightLCA ;
        }else{
            return leftLCA ;
        }

    }

    return nullptr;
}

int main(){

    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);

    TreeNode* p1 = root1->right->right;
    TreeNode* p2 =root1->right->left;

    TreeNode* ancst = firstAncestor(root1, p1, p2);

    if (ancst) {
        cout << "p1 :" << p1->val << " and p2 : " << p2->val << "\nTheir ancestor is : "<< ancst->val<<endl;
    } else {
         cout << "p1 is: " << p1->val << " and the p2 is: " << p2->val << "; their ancestor is : "<< "NULL "<<endl;
    }
   
    
    return 0;
}



