// https://godbolt.org/z/aczhqPMve

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

void insert(Node* &head, int d){
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
//------------------------------------------------------------------//

// 2.3 remove middle
/*
slow/fast pointer
*/

void removeMid(Node* head){
    if(head == nullptr ||head->next == nullptr ){
        return;
    }
    Node* pre = nullptr;
    Node* slow = head;

    Node* fast = head;

    while(fast !=nullptr && fast->next !=nullptr){
        fast = fast->next->next;
        
        pre = slow;
        slow = slow->next;
    }

    // remove mid, i.e. slow
    if(pre !=nullptr){
        pre->next = slow->next;
        delete slow;
    }
    
}



int main(){
    //generate new list
    Node* head = nullptr;
    for ( int i = 7; i > 0; i-- ) {
        insert(head, i);
    }

    cout << "Original List: ";
    printList(head);

    removeMid(head);

    
    cout <<"remove middle th elems, the list now is = \n "<<endl;

    printList(head);
    return 0;
}
