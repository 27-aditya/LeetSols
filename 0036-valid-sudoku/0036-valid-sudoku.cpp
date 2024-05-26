class Solution {
private:
bool checkSubgrid(vector<vector<char>>& board, int x, int y) {
    vector<int> hash(10, 0);
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                if (++hash[board[i][j] - '0'] > 1)
                    return false;
            }
        }
    }
    return true;
}
public:
bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        vector<int> row(10, 0), col(10, 0);
        for (int j = 0; j < 9; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                if (++row[board[i][j] - '0'] > 1)
                    return false;
            }
            if (board[j][i] >= '1' && board[j][i] <= '9') {
                if (++col[board[j][i] - '0'] > 1)
                    return false;
            }
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!checkSubgrid(board, i, j))
                return false;
        }
    }
    return true;
    }
};