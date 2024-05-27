class Solution {
private:
    void dfs(vector<vector<int>>&grid, int i, int j, int row, int col, int& currarea){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0)
            return;
        
        currarea++;
        grid[i][j] = 0;

        dfs(grid, i-1, j, row, col, currarea);
        dfs(grid, i+1, j, row, col, currarea);
        dfs(grid, i, j-1, row, col, currarea);
        dfs(grid, i, j+1, row, col, currarea);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxarea = 0;
        int currarea = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, row, col, currarea);
                    maxarea = max(currarea, maxarea);
                    currarea = 0;
                }
            }
        }   
        return max(maxarea, currarea); 
    }
};