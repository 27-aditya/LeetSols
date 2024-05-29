class Solution {
private:
    void dfs(vector<vector<char>>& board, int x, int y, int row, int col){
        if(x >= row || y >= col || x < 0 || y < 0 || board[x][y] != 'O')
            return;
        board[x][y] = 'E';

        dfs(board, x-1, y, row, col);
        dfs(board, x+1, y, row, col);
        dfs(board, x, y-1, row, col);
        dfs(board, x, y+1, row, col); 
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            dfs(board, i, 0, row, col);
            dfs(board, i, col-1, row, col);
        }

        for(int j = 0; j < col; j++){
            dfs(board, 0, j, row, col);
            dfs(board, row-1, j, row, col);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j <col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }
};