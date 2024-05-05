class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        vector<vector<string>> result;
        unordered_map<string, vector<string>>map;
        for(int i =0; i < strs.size(); i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            map[str].push_back(strs[i]);
        }
        for(auto i:map)
            result.push_back(i.second);
        return result;
    }
};