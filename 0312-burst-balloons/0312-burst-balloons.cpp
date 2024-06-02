class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>dp(400, vector<int>(400));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>j)dp[i][j]=0;
            }
        }
        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                int nas = -1;
                for(int k = i; k <= j; k++){
                    nas = max(nas, nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j] = nas;
            }
        }
        return dp[1][n];
    }
};