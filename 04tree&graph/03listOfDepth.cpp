// https://godbolt.org/z/s6KEqPrfT


#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class LinkedList{
    public:
        ListNode* head;
        LinkedList():head(nullptr){}

     // Insert a new node at the tail of the list
     void tailInsert(int val){
        ListNode* newnode = new ListNode(val);
        if(!head){
            head = newnode;
        }else{
            ListNode* cur = head;
            while(cur->next){
                cur = cur->next;
            }
            cur->next = newnode;
        }
     } 
     
     // print list
     void printList() const {
        ListNode* curr = head;
        while (curr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "nullptr" << endl;
    }

};


//------------------------impl: tree-> linkedlist -----------------------//

// using BFS

vector<LinkedList> buildListFromTree(TreeNode* root){
    vector<LinkedList> result;
    if(!root) return result;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){
        LinkedList levellist;
        int size = q.size(); //  have to write here, not in for loop because, q size is keeping changing.
        for(int i = 0; i<q.size();++i){
            TreeNode* curTreeNode = q.front();
            q.pop();
            levellist.insertAtTail(curTreeNode->val);
            if(curTreeNode->left) q.push(curTreeNode->left);
            if(curTreeNode->right) q.push(curTreeNode->right);
            
        }
        result.push_back(levellist);
    }
    return result;
}



int main(){
    // std::vector<int> input = {1,2,3,4,5,6,7};
    // TreeNode* root = createMinimalBST(input);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    vector<LinkedList> lists = buildListFromTree(root);

    for (int i = 0; i < lists.size(); ++i) {
        cout << "Level " << i << ": ";
        lists[i].printList();
    }
    return 0;
}



