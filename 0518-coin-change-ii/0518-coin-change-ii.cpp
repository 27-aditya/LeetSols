class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));

        for(int i = 0; i <= amount; i++){
            dp[0][i] = (i % coins[0] == 0);
        }

        for(int i = 1; i < n; i++){
            for(int target = 0; target <= amount; target++){
                long int nottake = dp[i-1][target];
                long int take = 0;
                if(target >= coins[i]) take = dp[i][target-coins[i]];
                dp[i][target] = take + nottake;
            }
        }
        return dp[n-1][amount];
    }
};