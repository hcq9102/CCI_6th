// https://godbolt.org/z/vx1jKzavW


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

// 2.2 find the kth elements to the last 
/*
slow/fast pointer
*/

int findKthToLast(Node* head, int k){
    if(head == nullptr){
        return 0;
    }

    Node* slow = head;
    Node* fast = head;

    int cnt = 0;

    while(fast !=nullptr){
        // move fast ptr walk k steps first
        while(fast!=nullptr && cnt<k){
            fast = fast->next;
            cnt++;
        }
        // move slow and fast together
        fast = fast->next;
        slow = slow->next;
    }

    return slow->val;
}



int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);
    
    int k = 3;
    int res = findKthToLast(head, k);
    cout << "the " << k <<"th elems to the last is = "<< res<<endl;


    //generate new list
    Node * head1 = nullptr;
    for ( int i = 7; i > 0; i-- ) {
        insert(head1, i);
    }

    cout << "Original List: ";
    printList(head1);

    int k1 = 2;
    int res1 = findKthToLast(head1, k1);
    cout << "the " << k1 <<"th elems to the last is = "<< res1<<endl;

   
    return 0;
}
