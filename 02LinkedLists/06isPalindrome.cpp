// https://godbolt.org/z/avf616ahc

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
//------------------------------------------------------------------//

// 2.6 palindrome

// use stack 

bool isPalindrome(Node* head){

    stack<int> s;

    Node* cur = head;
    while(cur != nullptr){
        int n = cur->val;
        s.push(n);
        cur = cur->next;
    }

    // compare origin list with stack
    Node* current = head;
    while(current != nullptr){
        int n = current->val;
        int num = s.top();
        if(num != n){
            return false;
        }
        s.pop();

        current = current->next;
    }
    return true;
}

int main(){
    //generate new list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(1);

    cout << "Original list: ";
    printList(head);
    
    if(isPalindrome(head)){
        cout << "this list is palindrome " <<endl;
    }else{
        cout << "this list is NOT palindrome " <<endl;
    }


    //generate new list
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(3);
    head1->next->next->next->next = new Node(2);
    head1->next->next->next->next->next = new Node(1);

    cout << "Original list: ";
    printList(head1);
    
    if(isPalindrome(head1)){
        cout << "this list is palindrome " <<endl;
    }else{
        cout << "this list is NOT palindrome " <<endl;
    }

    return 0;
}
