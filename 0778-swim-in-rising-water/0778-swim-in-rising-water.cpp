class Solution {
private:
    vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1)
            return 0;
        vector<vector<bool>>visited(n,vector<bool>(n));
        visited[0][0] = true;
        int result = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({result, 0, 0});

        while(!pq.empty()){
            vector<int> now = pq.top();
            pq.pop();

            result = max(result, now[0]);

            for(int i = 0; i < 4; i++){
                int x = now[1] + dirs[i][0];
                int y = now[2] + dirs[i][1];

                if(x < 0 || y < 0 || x >= n || y >= n || visited[x][y])
                    continue;

                if(x == n-1 && y == n-1)
                    return result;

                pq.push({grid[x][y],x,y});
                visited[x][y] = true;
            }
        }
        return -1;
    }
};