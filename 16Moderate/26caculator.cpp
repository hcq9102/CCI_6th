//https://godbolt.org/z/M4jMrK53q

/*
初始化：我们用 stack 来存储操作数的中间结果，current_number 用来构建当前的数字，current_operation 用来保存上一个运算符。
遍历字符串：在遍历过程中，根据字符的类型处理数字和运算符。
处理运算符：
+ 和 - 直接将数字推入栈或将其取反（对于 -）。
* 和 / 根据栈顶的值和当前数字进行计算，结果替换栈顶的值。
计算最终结果：遍历完成后，栈中包含了所有数字，通过求和得到最终结果

*/
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int calculator(string s){
    int n = s.size();
    int num = 0;

    char preOp = '+';
    stack<int> stk;

    for(int i = 0; i< n; i++){
        if(isdigit(s[i])){
            num = num*10 + (s[i] -'0');
        }

        if(i==n-1 || !isdigit(s[i]) && s[i]!=' '){
            if(preOp == '+'){
                stk.push(num);
            }else if(preOp == '-'){
                stk.push(-num);
            }else if(preOp == '*'){
                int top = stk.top();
                stk.pop();
                stk.push(num*top);
              
            }else if(preOp == '/'){
                int top = stk.top();
                stk.pop();
                stk.push(top /num);
            }
            // Update operation and reset number
            preOp = s[i];
            num = 0;//ready for next round (在这个if内，意思是 遇见一个新的op后，就开始重新计数，回到外部if)  
        }

        // Sum up all numbers in the stack
    
    }

        int res = 0;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    
}

int main() {
    cout << calculator("3+2*2") << endl;  // 输出: 7
    cout << calculator("3/2") << endl;    // 输出: 1
    cout << calculator("3+5 / 2") << endl; // 输出: 5
    
    return 0;
}
