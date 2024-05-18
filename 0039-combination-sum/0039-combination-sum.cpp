class Solution {
private:
    void dfs(vector<int>& candidates, int i, int target, vector<int>&curr, vector<vector<int>>&result){
        if( i >= candidates.size() || target < 0)
            return;
        
        if(target == 0){
            result.push_back(curr);
            return;
        }

        curr.push_back(candidates[i]);

        dfs(candidates, i, target-candidates[i], curr, result);

        curr.pop_back();

        dfs(candidates, i+1, target, curr, result);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>> result;
        dfs(candidates, 0 ,  target, curr, result);
        return result;    
    }
};