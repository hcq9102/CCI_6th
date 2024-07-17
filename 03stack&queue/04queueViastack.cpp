//https://godbolt.org/z/61WjWv6zb

#include <bits/stdc++.h>

using namespace std;
/*EnQueue(x)
  1) Push x to stack1 

  DeQueue(x)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) If stack2 is not empty, Pop the element from stack2 and return it.
*/
class Queue{
    private:
        stack<int> stack1, stack2;
    public:
        //en queue
        void enQueue(int data){
            stack1.push(data);
        } 

        int deQueue(){
            if(stack1.empty() && stack2.empty()){
                cout <<"Queue is empty: "<<endl;
                exit(0);
            }

            if(stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            int temp = stack2.top();
            stack2.pop();
            return temp;
        }  

        int size(){
            return stack1.size() + stack2.size();
        } 
};

int main(){
    Queue q;
    for(int i=0; i<5; i++){
        cout<<"EnQueue :"<<i<<'\n';
        q.enQueue(i);
    }
    cout<<"DeQueue :"<<q.deQueue()<<'\n';
    cout<<"DeQueue :"<<q.deQueue()<<'\n';
    for(int i=10; i<20; i++){
        cout<<"enQueue :"<<i<<'\n';
        q.enQueue(i);
    }
    cout<<"DeQueue :"<<q.deQueue()<<'\n';
    cout<<"DeQueue :"<<q.deQueue()<<'\n';

}

/*
入队操作 (enqueue) 总是将新元素压入 stack1。
出队操作 (dequeue)：
如果 stack2 为空，将 stack1 中的所有元素弹出并压入 stack2。然后从 stack2 中弹出栈顶元素。
如果 stack2 不为空，直接从 stack2 中弹出栈顶元素。
*/
