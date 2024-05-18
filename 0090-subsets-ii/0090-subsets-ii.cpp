class Solution {
private:
    void dfs(vector<int>&nums, int start, vector<int>&curr, vector<vector<int>>&result){
        if(find(result.begin(), result.end(), curr) == result.end())
            result.push_back(curr);
        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, i+1, curr, result);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, curr, result);
        return result;   
    }
};