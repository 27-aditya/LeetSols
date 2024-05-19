class Solution {
private:
    bool dfs(vector<vector<char>>&board, int row, int column, int m, int n, int index, string word){
        if(row < 0 || row >= m || column < 0 || column >= n || board[row][column] != word[index]){
            return false;
        }
        if(index == word.size()-1)
            return true;
        
        board[row][column] = '#';

        if (dfs(board, row+1, column, m, n, index+1, word) ||
            dfs(board, row-1, column, m, n, index+1, word) ||
            dfs(board, row, column+1, m, n, index+1, word) ||
            dfs(board, row, column-1, m, n, index+1, word))
            return true;

        board[row][column] = word[index];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0])
                    if(dfs(board, i, j, m, n, 0, word))
                        return true;
            }
        }
        return false;
    }
};