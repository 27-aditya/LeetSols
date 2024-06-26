class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int mx = nums[0];
        int mn = nums[0];
        int res = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) {
                swap(mx, mn);
            }
            
            mx = max(nums[i], nums[i] * mx);
            mn = min(nums[i], nums[i] * mn);
            
            res = max(res, mx);
        }

        return res;
    }
};
