class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;

        for(int i = 1; i < n; i++){
            dp[i] = min({dp[i2]*2, dp[i3]*3, dp[i5]*5});
            if(dp[i] == 2*dp[i2]) i2++;
            if(dp[i] == 3*dp[i3]) i3++;
            if(dp[i] == 5*dp[i5]) i5++;
        }
        return dp[n-1];
    }
};