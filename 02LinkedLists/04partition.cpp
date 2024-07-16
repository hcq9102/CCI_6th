//https://godbolt.org/z/q6oG8a9d5

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

void appendToTail(Node* &head, int d){
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

// 2.4 partition list

/*traverse linkedlist, and insertevery bigger or equal to x to tail and smaller values at head.*/

Node* partitionList(Node* head, int partition){
    if(head == nullptr ||head->next == nullptr ){
        return head;
    }
    Node* newlist = nullptr;

    Node* cur = head;

    while(cur !=nullptr){
        Node* newnode = new Node(cur->val);
        if(cur->val <partition){
            insert(newlist,cur->val) ;  
        }else{
            appendToTail(newlist, cur->val);
        }
        cur = cur->next;
    }
    return newlist;
    
}

// pair<Node*, Node*> partitionList(Node* head, int partition) {
//     Node* lessHead = nullptr;   // List for nodes less than partition
//     Node* greaterHead = nullptr; // List for nodes greater than or equal to partition

//     Node* cur = head;
//     while (cur != nullptr) {
//         if (cur->val < partition) {
//             appendToTail(lessHead, cur->val);
//         } else {
//             appendToTail(greaterHead, cur->val);
//         }
//         cur = cur->next; // Advance to the next node
//     }

//     return {lessHead, greaterHead};
// }


int main(){
    //generate new list
    Node* head = nullptr;
    for ( int i = 10; i > 0; i-- ) {
        insert(head, rand() % 9);
    }

    cout << "Original List: ";
    printList(head);

    int partition  = rand()%9;
     cout <<"the partition  =  "<<partition<< endl;

    cout <<"after partition, the list now is = \n "<<endl;
    Node* partitionedHead = partitionList(head, partition);
    printList(partitionedHead);

    return 0;
}
