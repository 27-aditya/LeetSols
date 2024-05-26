class Solution {
private:
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

             

            int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            for(auto dir : dirs){
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1'){
                    grid[nrow][ncol] = '0';
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int result = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    result++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        return result;
    }
};
