//https://godbolt.org/z/5Pe46rvsK

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

int height(TreeNode *node){
    if(node == nullptr) return 0; // have to add this for empty tree, otherwise, will lead to dereference of nullptr, its an undefined behavior

    int depth = 0;

    queue<TreeNode*> q;
    q.push(node);
    
    while(!q.empty()){
        depth++;
        int size = q.size();
        for(int i = 0; i<size; i++){
            TreeNode *cur = q.front();
            q.pop();

            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return depth;

}

bool IsBalanced(TreeNode *root){
    // recursive

    if(root == nullptr) return true;
    return abs(height(root->left) - height(root->right)) <=1 && IsBalanced(root->left)&&IsBalanced(root->right); 
}


int main(){
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    if(IsBalanced(root)){
        cout <<"Tree is balanced!"<<endl;
    }else{
        cout <<"Tree is NOT balanced!"<<endl;

    }

    cout <<"Another case: "<<endl;

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    root1->right->right->right = new TreeNode(8);
    root1->right->right->right->right = new TreeNode(9);


    if(IsBalanced(root1)){
        cout <<"Tree is balanced!"<<endl;
    }else{
        cout <<"Tree is NOT balanced!"<<endl;

    }
   
    return 0;
}



