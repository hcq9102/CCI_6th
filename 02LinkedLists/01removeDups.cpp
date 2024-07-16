
#include <bits/stdc++.h>

using namespace std;
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Node{
    public:
        int val;
        Node *next;
        
        Node():val(0),next(nullptr){}
        Node(int x):val(x),next(nullptr){}
        Node(int x, Node* next): val(x), next(next){}
};

// Declare global variable 'head' as a pointer to Node
Node* head = nullptr;

// Function to append a new node with given value to the end of the list
void appendToTail(int d){
    Node* newnode = new Node(d);

    if(head == nullptr){
        head = newnode;// If list is empty, make 'head' point to new node
    }else{
        Node* cur = head;
        while(cur->next !=nullptr){// Traverse to the end of the list
            cur = cur->next;
        }
        cur->next = newnode;// Append new node to the end
    }
}

void insert(int d){
    Node* newnode = new Node(d);
    newnode->next = head;// New node points to current 'head'
    head = newnode; // Update 'head' to point to the new node
}


void printList(Node* head){
    Node *cur = head;
    while(cur !=nullptr){
        cout << cur->val <<" ";
        cur = cur->next;
    }

    cout <<endl;
}
//--------------------------- implements ---------------------------------------//

// 2.1 remove dups
/*
METHOD 1:
runner helper pointer
*/

void removeDups(Node* head){
    if(head == nullptr || head&&head->next==nullptr){
        return;
    }
    // cur traverse each node, as anchor
    // use runner ptr to move after current node and compare with cur node
    /*
    1-2-3-4-1-6
    (1). cur = 1,
            runner move from 1-2-3-4-1-6 (remove 1)
    (2). cur = 2,
            runner move from 2-3-4-6
    (3). cur = 3,
            runner move from 3-4-6
       ....                     
    
    O(n^2)
    */

    Node* cur = head;
    while(cur !=nullptr){
        Node* runner = cur;
        while(runner->next !=nullptr){
            if(runner->next->val == cur->val){
                runner->next = runner->next->next;
            }else{
                runner = runner->next;
            }  
        }
        cur = cur->next;
    }

}


/*
METHOD 2:
hash set

time: O(n)
*/


void removeDups_set(Node* head){
    if(head == nullptr || head&&head->next==nullptr){
        return;
    }

    unordered_set<int> seen;

    Node* cur = head;
    Node* pre = nullptr;

    while(cur !=nullptr){
        if(seen.find(cur->val) != seen.end()){
            //remove
            pre->next = cur->next;
            cur = cur->next;
        }else{
            seen.insert(cur->val);
            pre = cur;
            cur = cur->next;
        }
    }
}

int main(){

    cout << "--------method1--------- "<<endl;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(1);

    cout << "Original List: ";
    printList(head);
    

    removeDups(head);
    cout << "after removing duplicates, List is: ";
    printList(head);

    cout << "--------method2--------- "<<endl;


    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(4);
    head1->next->next->next->next->next = new Node(1);

    cout << "Original List: ";
    printList(head1);
    cout << "--------method1--------- "<<endl;

    removeDups_set(head1);
    cout << "after removing duplicates, List is: ";
    printList(head);

    return 0;
}
