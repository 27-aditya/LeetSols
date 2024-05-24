class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int ans = 0;
        int prev2 = 0;
        int curr = 0;
        int cnt = 0;

        for(int i = 0; i < n-1; i++){
            int take = nums[i] + prev2;
            int nottake = ans;

            curr = max(take, nottake);
            prev2 = ans;
            ans = curr;
        }

        cnt = 0;
        prev2 = 0;
        curr = 0;
        int ans2 = 0;
        for(int i = 1; i < n; i++){
            int take = nums[i] +prev2;
            int nottake = ans2;

            curr = max(take, nottake);
            prev2 = ans2;
            ans2 = curr;
        }
        return max(ans, ans2);
    }
};