class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        if(nums[0] == 0)
            return false;
        int n = nums.size();
        int i = 0;
        int maxjump = 1;
        while(i < n-1 && maxjump >= 0){
            int j = i;
            maxjump = max(maxjump, nums[i]);
            while(j != n-1){
                j += nums[j];
                if(j >= n-1)
                    return true;
                if(nums[j] == 0)
                    break;
            }
            i++;
            maxjump--;
        } 
        return false;
    }
};