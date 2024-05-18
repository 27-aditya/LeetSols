class Solution {
private:
    void dfs(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& result, int start) {
        if (target == 0 && (find(result.begin(), result.end(), curr) == result.end())) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) continue;
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, curr, result, 0);
        return result;    
    }
};