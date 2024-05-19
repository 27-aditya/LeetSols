class Solution {
private:
    bool ispalindrome(string s){
        string p = s;
        reverse(p.begin(), p.end());
        return p == s;
    }
    void dfs(string s, int start, vector<string>&curr, vector<vector<string>>&result){
        if(start == s.size()){
            result.push_back(curr);
            return;
        }

        for(int i = start; i < s.size(); i++){
            if(ispalindrome(s.substr(start, i+1-start))){
                curr.push_back(s.substr(start, i+1-start));
                dfs(s, i+1, curr, result);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>curr;
        dfs(s, 0, curr, result);
        return result;
    }
};