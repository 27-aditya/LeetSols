class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for(int i = 1; i < amount+1; i++){
            for(int j = 0; j < n; j++){
                if(i-coins[j] >= 0)
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
        if(dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};