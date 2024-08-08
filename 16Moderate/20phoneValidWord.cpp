#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

// 映射表
const std::unordered_map<char, std::string> PHONE_MAPPING = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

// 生成所有可能的字母组合
void backtrack(const std::string& digits, const std::unordered_map<char, std::string>& phone_map,
               int index, std::string& path, std::vector<std::string>& combinations) {
    if (index == digits.length()) {
        combinations.push_back(path);
        return;
    }
    
    char digit = digits[index];
    if (phone_map.find(digit) != phone_map.end()) {
        const std::string& letters = phone_map.at(digit);
        for (char letter : letters) {
            path.push_back(letter);
            backtrack(digits, phone_map, index + 1, path, combinations);
            path.pop_back();
        }
    }
}

// 生成匹配的单词
std::vector<std::string> get_combinations(const std::string& digits) {
    std::vector<std::string> combinations;
    if (digits.empty()) return combinations;
    
    std::string path;
    backtrack(digits, PHONE_MAPPING, 0, path, combinations);
    return combinations;
}

// 从有效单词列表中筛选匹配的单词
std::vector<std::string> get_valid_words(const std::string& digits, const std::unordered_set<std::string>& word_set) {
    std::vector<std::string> possible_words = get_combinations(digits);
    std::vector<std::string> result;
    
    for (const std::string& word : possible_words) {
        if (word_set.find(word) != word_set.end()) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
    // 示例有效单词列表
    std::unordered_set<std::string> valid_words = {"tree", "used", "tres", "uused"};
    
    // 输入
    std::string input_digits = "8733";
    
    // 获取匹配的单词
    std::vector<std::string> output_words = get_valid_words(input_digits, valid_words);
    
    // 输出结果
    for (const std::string& word : output_words) {
        std::cout << word << std::endl;
    }
    
    return 0;
}
