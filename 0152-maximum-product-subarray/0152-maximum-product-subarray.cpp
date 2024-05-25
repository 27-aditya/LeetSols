class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>mn(n);
        vector<int>mx(n);
        int res = nums[0];
        mn[0] = nums[0];
        mx[0] = nums[0];

        for(int i = 1; i < n;i++){
            mx[i] = max(nums[i]*mn[i-1], nums[i]*mx[i-1]);
            mn[i] = min(nums[i]*mx[i-1], nums[i]*mn[i-1]);
            mx[i] = max(nums[i], mx[i]);
            mn[i] = min(nums[i], mn[i]);
        }
        sort(mx.begin(), mx.end());
        sort(mn.begin(), mn.end());

        return max(mx.back(), mn.back());
    }
};