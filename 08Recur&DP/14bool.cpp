//https://godbolt.org/z/jKcGP39rd

#include <bits/stdc++.h>

using namespace std;

// Memoization maps
unordered_map<string, int> memoTrue;
unordered_map<string, int> memoFalse;

// Helper function to evaluate the expression
int countEvalHelper(const string &expression, bool result) {
    if (memoTrue.find(expression) != memoTrue.end() && result) {
        return memoTrue[expression];
    }
    if (memoFalse.find(expression) != memoFalse.end() && !result) {
        return memoFalse[expression];
    }
    
    int n = expression.size();
    if (n == 1) {
        // Base case: single operand
        bool value = (expression[0] == '1');
        if (value == result) {
            return 1;
        }
        return 0;
    }
    
    int count = 0;
    for (int i = 1; i < n; i += 2) {
        char op = expression[i];
        string leftExpr = expression.substr(0, i);
        string rightExpr = expression.substr(i + 1);
        
        int leftTrue = countEvalHelper(leftExpr, true);
        int leftFalse = countEvalHelper(leftExpr, false);
        int rightTrue = countEvalHelper(rightExpr, true);
        int rightFalse = countEvalHelper(rightExpr, false);
        
        int totalWays = 0;
        
        if (op == '&') {
            if (result) {
                totalWays = leftTrue * rightTrue;
            } else {
                totalWays = leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
            }
        } else if (op == '|') {
            if (result) {
                totalWays = leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                totalWays = leftFalse * rightFalse;
            }
        } else if (op == '^') {
            if (result) {
                totalWays = leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                totalWays = leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }
        
        count += totalWays;
    }
    
    if (result) {
        memoTrue[expression] = count;
    } else {
        memoFalse[expression] = count;
    }
    
    return count;
}

// Main function to count the number of ways to evaluate the expression to the given result
int countEval(const string &expression, bool result) {
    return countEvalHelper(expression, result);
}

int main() {
    // Test cases
    cout << countEval("1^0|0|1", false) << endl; // Output: 2
    cout << countEval("0&0&0&1^1|0", true) << endl; // Output: 10
    return 0;
}
