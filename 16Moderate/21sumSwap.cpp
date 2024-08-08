#include <iostream>
#include <optional>
#include <algorithm> // for std::min and std::max
#include <bits/stdc++.h>
using namespace std;

/*
16.21 和交换（Sum Swap）：给定两个整数数组，找到一对值（每个数组一个值），能够满足互换这些值以使两个数组具有相同的总和。
 Input: {4, 1, 2, 1, 1, 2} and {3, 6, 3, 3}
 Output: {1, 3}
*/

vector<int> sumSwap(vector<int>& v1, vector<int>& v2){
   
    set<int> s2;
    int sum1 = 0;
    int sum2 = 0;

    for(auto num: v1){
        sum1+=num;
   
    }

    for(auto num2: v2){
        sum2+=num2;
        s2.insert(num2);
    }

    int dif = std::abs(sum1-sum2);

    for(auto elem: v1){
        if(elem>=dif){
            continue;
        }else{
            int temp= abs(dif - elem);
            if(s2.count(temp)>0){
                return {elem, temp};
            }
        }
    }
// 如果没有找到符合条件的值对，返回一对无效值
    return {-1,-1};
}

int main(){
    vector<int> v1 = {4, 1, 2, 1, 1, 2};
    vector<int> v2 = {3, 6, 3, 3};
    vector<int> res = sumSwap(v1,v2);

    for(auto elm: res){
        cout << elm<<" ";
    }

    cout <<endl;


    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {6, 7, 8, 9, 10};

    vector<int> res1 = sumSwap(array1,array2);

    for(auto elm: res1){
        cout << elm<<" ";
    }


    return 0;

}

