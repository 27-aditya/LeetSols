class Solution {
private:
    bool issafe(int col, int row, vector<string>board, int n){
        int row1 = row;
        int col1 = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        row = row1;
        col = col1;

        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        col = col1;
        row = row1;

        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(int col, vector<string>&board, vector<vector<string>>&result, int n){
        if(col == n){
            result.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(issafe(col, row, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, result, n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        solve(0, board, result, n);
        return result;
    }
};