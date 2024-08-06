// https://godbolt.org/z/zbYojn8f6

#include <bits/stdc++.h>
using namespace std;
// Sort the Array: Start by sorting the array to easily access the smallest and largest elements.
//Rearrange the Sorted Array: Use a two-pointer approach to rearrange the elements in such a way that they form a peak and valley pattern.
//每次拿一个最大值和最小值放入res

vector<int> peakValley(vector<int> & vec){
    int left = 0;
    int right = vec.size()-1;

    vector<int> res;

    sort(vec.begin(), vec.end());

    while(left<right){
        res.push_back(vec[right]);
        res.push_back(vec[left]);

        right--;
        left++;
    }

    //If there is an odd number of elements, add the middle element
    if (left == right) {
        res.push_back(vec[left]);
    }

    return res;
}

int main() {
    std::vector<int> nums = {5, 3, 1, 2, 3};
     cout << "origin Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result = peakValley(nums);
    
    cout << "Peaks and Valleys Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
