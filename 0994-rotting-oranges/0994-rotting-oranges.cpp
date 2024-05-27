class Solution {
private:
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        int time = -1;
        queue<pair<int,int>>q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        q.push({-1,-1});

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i == -1){
                time++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }
            else{ 
                for(auto dir : dirs){
                    int nr = i+dir[0];
                    int nj = j+dir[1];
                    if(nr >= 0 && nj >= 0 && nr < row && nj < col && grid[nr][nj] == 1){
                        grid[nr][nj] = 2; 
                        fresh--;
                        q.push({nr,nj});
                    }
                }
            }
        }

        if(fresh == 0)
            return time;
        return -1;
    }
};