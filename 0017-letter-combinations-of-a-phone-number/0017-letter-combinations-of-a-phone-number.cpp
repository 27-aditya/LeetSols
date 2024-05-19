class Solution {
private:
    void dfs(string digits, int index, unordered_map<char, string>&m, string& curr, vector<string>&result){
        if(index == digits.size()){
            result.push_back(curr);
            return;
        }
        string str = m[digits[index]];
        for(int i = 0; i < str.size(); i++){
            curr.push_back(str[i]);
            dfs(digits, index+1, m, curr, result);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0)
            return result;
        unordered_map<char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string curr = "";

        dfs(digits, 0, map, curr, result);
        return result;
    }
};