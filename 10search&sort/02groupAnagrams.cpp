class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;//sorted str-->orgin str

        vector<vector<string>> res;

        for(auto &str: strs){
            string word = str;
            sort(word.begin(), word.end());
            
            mp[word].push_back(str);
        }

        for(auto& entry: mp){
            res.push_back(entry.second);
        }
        return res;

    }
};
