#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper functions
const vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string convertHundreds(int num) {
    string result;
    if (num >= 100) {
        result += below_20[num / 100] + " Hundred ";
        num %= 100;
    }
    if (num >= 20) {
        result += tens[num / 10] + " ";
        num %= 10;
    }
    if (num > 0) {
        result += below_20[num] + " ";
    }
    return result;
}

string numberToWords(int num) {
    if (num == 0) return "Zero";
    
    string result;
    int i = 0;
    
    while (num > 0) {
        cout<<"num%1000= "<< num % 1000 <<endl;
        if (num % 1000 != 0) {
            result = convertHundreds(num % 1000) + thousands[i] + " " + result;
            cout << "res = " <<result<<endl;
        }
        num /= 1000;
        ++i;
    }
    
    // Trim leading and trailing spaces
    if (!result.empty() && result[result.size() - 1] == ' ') {
        result.pop_back();
    }
    
    return result;
}

int main() {
    int number = 12500; // Example number
    cout << "Number in words: " << numberToWords(number) << endl;
    return 0;
}
