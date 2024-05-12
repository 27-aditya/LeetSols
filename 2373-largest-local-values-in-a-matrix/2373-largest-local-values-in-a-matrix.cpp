#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
class Solution {
private:
    int maxdigit(vector<vector<int>>& grid, int x, int y){
        int md = INT_MIN;
        for(int i = x; i < x+3; i++){
            for(int j = y; j < y+3; j++){
                md = max(md, grid[i][j]);
            }
        }
        return md;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = grid.size();
        int m = n-2;
        vector<vector<int>>result(m, vector<int>(m,0));
        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < n-2; j++){
                result[i][j] = maxdigit(grid, i, j);
            }
        }
        return result;
    }
};