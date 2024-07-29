

#include <bits/stdc++.h>

using namespace std;

void printLastKLines(const std::string& filename, size_t K) {

    // deque with K capacity

    std::ifstream file(filename);

    if(!file.is_open()){
        throw "open file error";
    }

    std::deque<string> lines;
    string line;

    while(std::getline(file, line)){
        if(lines.size() == K){
            lines.pop_front(); 
        }
        lines.push_back(line);
    }

    file.close();

    // 打印最后 K 行
    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }

}

int main() {
    std::string filename = "example.txt"; 
    size_t K = 5; // 

    printLastKLines(filename, K);

    return 0;
}
