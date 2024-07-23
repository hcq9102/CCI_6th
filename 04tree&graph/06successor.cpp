// https://godbolt.org/z/ja3418q13

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// find the next node of p: leftmost of right subtree.
TreeNode* Successor(TreeNode *root, TreeNode *p){
    if(root == nullptr) return nullptr;

    TreeNode *cur = root;
    TreeNode *ans = nullptr; 

    while(cur){
        if(cur->val > p->val){
            ans = cur;// ans for storing the smallest val among the nodes that greater than  p
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



/*
判断当前节点值与 p 的值关系：

如果 cur 的值大于 p 的值，则 cur 有可能是我们要找的后继节点。
此时，更新 ans 为 cur，并继续在 cur 的左子树中寻找可能的更小的后继节点。
如果 cur 的值小于或等于 p 的值，则后继节点必定在 cur 的右子树中。此时，将 cur 移动到 cur 的右子节点。

跳出循环：

当 cur 为空时，循环结束。这时，ans 保存的就是大于 p 的最小节点。

*/



