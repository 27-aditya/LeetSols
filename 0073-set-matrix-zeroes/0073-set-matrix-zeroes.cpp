class Solution {
private:

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        queue<pair<int, int>>q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for(int i = 0; i < col;i++)
                matrix[nrow][i] = 0;

            for(int i = 0; i < row;i++)
                matrix[i][ncol] = 0;
        }
    }
};