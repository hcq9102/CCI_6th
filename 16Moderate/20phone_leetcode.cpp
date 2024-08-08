//leetcode 17： 
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/



// BFS
class Solution {
public:

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        if (digits.empty()) return res;

        int n = digits.size();
        queue<string> q;

        q.push("");

        while(!q.empty()){
            string cur = q.front();
            q.pop();

            // collect res when cur size == n
            if(cur.size() ==n){
                res.push_back(cur);
                continue;
            }

            char digit = digits[cur.size()];
            string letters = mp[digit];

            for(auto c: letters){
                q.push(cur+c);
            }
        }

    return res;
    }
};


// DFS(backtrack: find all possible ans)
class Solution {
public:

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        if (digits.empty()) return res;

        // backtrack
        backtrack(digits, mp, 0, "", res);

        return res;
    }

    void backtrack(string &digits,unordered_map<char, string> &mp, int index, string cur, vector<string> &res){
        // if satisfied the condition, add to res
        if(index == digits.size()){
            res.push_back(cur);
            return;
        }

        //choose
        char digit = digits[index];
        string letters = mp[digit];

        for(auto c: letters){
             // choose , update cur
            cur +=c;
            //cout << "cur0 = "<< cur<<endl;
            backtrack(digits, mp, index+1, cur, res);
            cur.pop_back();//unchoose

            //cout << "cur = "<< cur<<endl;

            /*
            a--->
                d,e,f

                处理d:
                结合成ad,然后回退为a

                处理e:
                结合成ae,然后回退为a

                处理f:
                结合成af,然后回退为a
////////////////////////////////////////////////
                继续退回为“”， 处理 b
            b--->
                d,e,f

                处理d:
                结合成bd,然后回退为b

                处理e:
                结合成be,然后回退为b

                处理f:
                结合成bf,然后回退为b

              
           ////////////////////////////////////////////////
                继续退回为“”， 处理 c
            c--->
                d,e,f

                处理d:
                结合成cd,然后回退为c

                处理e:
                结合成ce,然后回退为c

                处理f:
                结合成cf,然后回退为c

                继续退回为“”         

            */
        }

    }
};
