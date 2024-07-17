// https://godbolt.org/z/sYr4q9M1x

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
//---------------------------------------------implements 2.5---------------------------------------------------------------------//

// 2.5 sum list

// input 6-1-7 is 716

int sumTwoList(Node* &list1, Node* &list2){
    // convert to int
    // sum
    int v1 = 0;
    int v2 = 0;

    Node* cur1 = list1;
    Node* cur2 = list2;

    int k = 0;
    while(cur1 !=nullptr){
        int n = cur1->val;
        v1 += n*pow(10,k);
        k++;
        cur1 = cur1->next;
    }
    cout << v1<<endl;

    int d = 0;
    while(cur2 !=nullptr){
        int n = cur2->val;
        v2 += n*pow(10,d);
        d++;
        cur2 = cur2->next;
    }
    cout << v2<<endl;

    return v1+v2;
}


// ------------------------------------------------follow up------------------------------------------------
// input 6-1-7 is 617

int sumTwoList_rev(Node* &list1, Node* &list2){
    // convert to int
    // sum
    int v1 = 0;
    int v2 = 0;

    Node* cur1 = list1;
    Node* cur2 = list2;
    while(cur1 !=nullptr){
        int n = cur1->val;
        v1 = v1*10 + n;
        cur1 = cur1->next;
    }
    cout << v1<<endl;

    while(cur2 !=nullptr){
        int n = cur2->val;
        v2 = v2*10 + n;
        cur2 = cur2->next;
    }
    cout << v2<<endl;

    return v1+v2;
}

int main(){
    //generate new list
    Node* head1 = nullptr;
    for ( int i = 3; i > 0; i-- ) {
        insert(head1, rand() % 9);
    }

    Node* head2 = nullptr;
    for ( int i = 3; i > 0; i-- ) {
        insert(head2, rand() % 9);
    }

    cout << "Original List1: ";
    printList(head1);
    cout << "Original List2: ";
    printList(head2);

    int res = sumTwoList(head1, head2);

    cout << "two lists' sum is : " <<res<<endl;

    //generate another new list
    Node* head3 = nullptr;
    for ( int i = 3; i > 0; i-- ) {
        insert(head3, rand() % 9);
    }

    Node* head4 = nullptr;
    for ( int i = 3; i > 0; i-- ) {
        insert(head4, rand() % 9);
    }

    cout << "Original List1: ";
    printList(head3);
    cout << "Original List2: ";
    printList(head4);

    int res2 = sumTwoList_rev(head3, head4);

    cout << "two lists' sum is : " <<res2 <<endl;

    return 0;
}
