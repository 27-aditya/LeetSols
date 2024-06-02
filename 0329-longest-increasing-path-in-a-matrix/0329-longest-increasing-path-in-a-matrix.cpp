class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int result = 0;
        vector<vector<int>>dp(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++){
            for(int j =0 ; j < col; j++){
                result = max(result, dfs(matrix, i, j, row, col, dp));
            }
        }
        return result;
    }
private:
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& matrix, int i, int j, int row, int col,vector<vector<int>>&dp){
        if(dp[i][j] != -1)
            return dp[i][j];

        int cnt = 1;

        for(auto dir : dirs){
            int nrow = i + dir[0];
            int ncol = j + dir[1];
            if(nrow >= 0 && ncol >= 0 && nrow < row && ncol < col && matrix[nrow][ncol] > matrix[i][j])
                cnt = max(1 + dfs(matrix, nrow, ncol, row, col, dp), cnt);
        }

        dp[i][j] = cnt;
        return cnt;
    }
};