class Solution {
private:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,+1}};
    void dfs(vector<vector<int>>&heights, int i , int j, int row, int col, vector<vector<bool>>&visited){
        visited[i][j] = true;

        for(auto dir : dirs){
            int nrow = i + dir[0];
            int ncol = j + dir[1];
            if(nrow >= 0 && ncol >= 0 && nrow < row && ncol < col && !visited[nrow][ncol])
                if(heights[nrow][ncol] >= heights[i][j]){ 
                    dfs(heights,nrow,ncol,row, col, visited);

                }
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(row, vector<bool>(col,0));
        vector<vector<bool>>atlantic(row,  vector<bool>(col,0));
        
        for(int i = 0; i < row; i++){
            dfs(heights, i, 0, row, col, pacific);
            dfs(heights, i, col-1, row, col, atlantic);
        }
        for(int j = 0; j < col; j++){
            dfs(heights, 0, j, row, col, pacific);
            dfs(heights, row-1, j, row, col, atlantic);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};