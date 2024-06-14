class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int prev = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= prev){
                cnt += prev+1-nums[i];
                prev++;
            }
            else
                prev = nums[i];
        }
        
        return cnt;
    }
};