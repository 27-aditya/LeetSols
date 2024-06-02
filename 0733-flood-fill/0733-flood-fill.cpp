class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;

        int startcolor = image[sr][sc];
        dfs(image, sr, sc, color, startcolor);
        return image;
    }
private:
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>&image, int i, int j, int color, int startcolor){
        int row = image.size();
        int col = image[0].size();
        image[i][j] = color;

        for(auto dir: dirs){
            int nrow = i + dir[0];
            int ncol = j + dir[1];
            if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && image[nrow][ncol] == startcolor)
                dfs(image, nrow, ncol, color, startcolor);
        }
    }    
};