//https://godbolt.org/z/jqEMbhMd8


#include <bits/stdc++.h>

using namespace std;
/*
sort stack: 
    use addtional stack sorted, and itself for extra storage:

sorted: store the element in sorted, the top is the maximum.

if s.top() < sorted.top():
   then sorted.top() re-enqueue s.   
*/

//--------------------------------------------------------------//
stack<int> sortStack(stack<int> &s){
   stack<int> sortedStack;
   

    while(!s.empty()){
        
        // pop top of s
        int temp = s.top();
        s.pop();
        
        //pop the elem from sortedStack, if sorted.top()>temp，and push into s again.
        while(!sortedStack.empty() && temp < sortedStack.top()){
            s.push(sortedStack.top());
            sortedStack.pop();
        }

        // 将temp压入sortedStack中
        sortedStack.push(temp);

    }
    return sortedStack;
}


int main(){
    stack<int> s;
    s.push(1);
    s.push(6);
    s.push(5);
    s.push(4);
    
    stack<int> sorted = sortStack(s);

    cout << "Sorted Stack: ";
    while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }
    cout << endl;
    
    return 0;

}
