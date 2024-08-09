//leetcode 290
//https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::istringstream stream(s);
        vector<string> words;
        string word;

        while(stream>>word){
            words.push_back(word);
        }

        if(pattern.size() !=words.size()) return false;

        unordered_map<char, string> charTostr;
        unordered_set<string> exist;// check if exist multiple mapping

        for(int i = 0; i< pattern.size(); i++){
            if(charTostr.find(pattern[i]) == charTostr.end()){//new mapping
                if(exist.contains(words[i])){ // multiple letters -->one word
                    return false;
                }
                charTostr[pattern[i]] = words[i];
                exist.insert(words[i]);
            }else{
                if(charTostr[pattern[i]] != words[i]){
                    return false;
                }
            }
        }
        return true;
   
    }
};
