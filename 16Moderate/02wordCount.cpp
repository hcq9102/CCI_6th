

#include <iostream>
#include <fstream>
#include <sstream> // 确保包含这个头文件
#include <string>

#include <unordered_map>
using namespace std;

class wordFrequency{

    private:
        std::unordered_map<std::string, int> wordCounts;

    public:
        wordFrequency(){}

        // 从文件中加载文本并计算单词频率
        void loadFromFile(const std::string& filename){
            std::ifstream file(filename);

            if(!file.is_open()){
                throw "cannot open file";
            }

            string line;
            while(std::getline(file,line)){
                processLine(line);
            }

            file.close();
        }
        // 从字符串中处理一行文本
        void processLine(const string &line){
            std::istringstream stream(line);

            string word;
            while(stream >>word){
                wordCounts[word]++;
            }
        }

         // get freq
         int getFrequency(string &word){
            //auto it = wordCounts.find(word);
            // if(it != wordCounts.end()){
            //     return it->second;
            // }else{
            //     return 0;
            // } 
            if(wordCounts.find(word) != wordCounts.end()){
                return wordCounts.find(word)->second;
            }else{
                return 0;
            }

         }
};



int main() {
    wordFrequency counter;
    counter.loadFromFile("book.txt");

    string word;

    std::cout << "input words frequency: ";
    while (std::cin >> word) {
        std::cout << "word '" << word << "' frequency: " << counter.getFrequency(word) << std::endl;
        std::cout << "ctrl D to exit: ";
    }

    return 0;
}
