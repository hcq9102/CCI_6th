

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

using namespace std;

int findSmallestDifference(vector<int>& arr1, vector<int>& arr2) {
    // Sort both arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    int minDifference = INT_MAX;

    // Traverse both arrays
    while (i < arr1.size() && j < arr2.size()) {
        int diff = abs(arr1[i] - arr2[j]);
        minDifference = min(minDifference, diff);

        // Move the pointer of the smaller value
        if (arr1[i] < arr2[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return minDifference;
}

int main() {
    vector<int> arr1 = {1, 3, 15, 11, 2};
    vector<int> arr2 = {23, 127, 235, 19, 8};

    int result = findSmallestDifference(arr1, arr2);
    cout << "The smallest difference is: " << result << endl;

    return 0;
}
