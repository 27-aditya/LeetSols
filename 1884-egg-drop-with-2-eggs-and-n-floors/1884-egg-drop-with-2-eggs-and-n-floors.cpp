class Solution {
public:
    int twoEggDrop(int n) {
        int floor = n;
        int egg = 2;
        vector<vector<int>>dp(n+1, vector<int>(3, 0));

        int m = 0;

        while(dp[m][egg] < n){
            m++;
            for(int i = 1; i <= egg; i++){
                dp[m][i] = 1 + dp[m-1][i-1] + dp[m-1][i];
            }
        }

        return m;
    }
};