// https://godbolt.org/z/96GEaGba5

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

void printList(Node* head){
    Node *cur = head;
    while(cur !=nullptr){
        cout << cur->val <<" ";
        cur = cur->next;
    }

    cout <<endl;
}
//------------------------------------------------------------------//

// 2.7 intersection

/* 
use math:

if intersect:

     a ---> c------>null
            ^
            |
  b----------

 pA = headA; 
 pB = headB;
 
 first, eliminate distance between two lists by move pA and pB pointers:
        when pA reach to null, make it point to headB;
        when pB reach to null, make it point to headA;

        NOW, pA and pB can reach to the last end at the same distance.
        therefore, they can reach to the intersection at the same time.
    a+c +b = b+c +a;

        if there is no intersection, then pA and pB will reach the(end) null at the same time.
    a+b = b+a;
       

*/

Node* isIntersection(Node* headA, Node* headB){
    if(headA == nullptr || headB==nullptr) return nullptr;
    
    Node* pA = headA;
    Node* pB = headB;

    while(pA !=pB){
        pA = pA ==nullptr ? headB: pA->next;
        pB = pB == nullptr? headA : pB->next;
    }
    return pA; // or pB

}

int main(){
    //generate new list
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(5);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(1);

    //generate another new list
    Node* head1 = new Node(3);
    head1->next = new Node(4);
    head1->next->next = new Node(6);
    head1->next->next->next = head->next->next->next->next ;
  

    cout << "Original list: ";
    printList(head);
    printList(head1);
    Node* res = isIntersection(head,head1);
    if(res){
        cout << "Two lists have intersection at node : " << res->val<<endl;
    }else{
        cout << "Two lists has no intersection! " <<endl;
    }


    return 0;
}
