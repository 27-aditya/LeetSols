class Solution {
private:
    void dfs(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], curr, result, i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> result;
        dfs(candidates, target, curr, result, 0);
        return result;    
    }
};
