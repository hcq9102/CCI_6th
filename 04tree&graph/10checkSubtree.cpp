//https://godbolt.org/z/ebjG9noPP


#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

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

// -----------imlp 10--------------------------------------------//

void inorderString(TreeNode *root, string s){
    if(root == nullptr){
        s +="x";
        return;
    }

    s+=root->val;
    inorderString(root->left, s);
    inorderString(root->right, s);
}

bool checkSubtree(TreeNode* root, TreeNode* subtree){
    string s1 = "";
    string s2 = "";

    inorderString(root, s1);
    inorderString(subtree, s2);

    return s1.find(s2) != string::npos;

}


int main() {
    // Hardcoded input sequence
    vector<int> values = {3, 2, 5, 1, 4};

    TreeNode* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    vector<int> subtree = {5, 4};

    TreeNode* subroot = nullptr;
    for (int val : values) {
        subroot = insert(root, val);
    }

    if(checkSubtree){
        cout << "contain this subtree! "<<endl;
    }else{
        cout << "NOT a contain subtree! "<<endl;
    }
    

    return 0;
}
