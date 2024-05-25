class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int ts = 0;
        for(int i = 0;i < n;i++){
            ts += nums[i];
        }
        if(ts%2 == 1)
            return false;
        int hs = ts/2;
        vector<bool> prev(hs+1, 0);
        vector<bool> curr(hs+1, 0);
        prev[0] = curr[0] = true;

        for(int i = 1; i < n; i++){
            for(int target = 1; target <= hs; target++){
                bool nottake = prev[target];
                bool take = false;
                if(nums[i] <= target) take = prev[target-nums[i]];
                curr[target] = take | nottake; 
            }
            prev = curr;
        }
        return prev[hs];
    }
};