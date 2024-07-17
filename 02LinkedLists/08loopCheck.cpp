//https://godbolt.org/z/9s3W3sqsz


#include <bits/stdc++.h>

using namespace std;

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

// 2.7 loop detection:

/* 
fast/slow pointer:
fast:two times of slow pointer.

fast will catch up slow again at the begin loop

*/

bool isLoop(Node* head){
    if(head == nullptr ) return false;
    
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false; 

}

int main(){
    //generate new list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;
  

    //cout << "Original list: ";
    //printList(head);
   
    if(isLoop(head)){
        cout << "This list has a loop  " <<endl;
    }else{
        cout << "This list has NO loop !" <<endl;
    }

    return 0;
}
