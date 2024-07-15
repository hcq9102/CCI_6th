//https://godbolt.org/z/r7hq3MPsW
#include <bits/stdc++.h>

using namespace std;


std::string replaceSpaces(const std::string &str) {
    std::string result = str;
    std::string toReplace = " ";
    std::string replacement = "20%";
    size_t pos = 0;
  
    while ((pos = result.find(toReplace, pos)) != std::string::npos) {
        result.replace(pos, toReplace.length(), replacement);
        pos += replacement.length();
    }

    return result;
}

int main() {
    std::string s = "Hello World, this is a test.";
    std::string result = replaceSpaces(s);
    std::cout << result << std::endl; // 输出 "Hello20%World,20%this20%is20%a20%test."
    return 0;
}
