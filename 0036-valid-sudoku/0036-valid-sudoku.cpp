class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> hash(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash[board[i][j]-'0']++;
                }
            }
            for(int i =0;  i < 10; i++){
                if(hash[i] > 1)
                    return false;
            }
        }
        for(int i = 0; i < 9; i++){
            vector<int> hash(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] >= '1' && board[j][i] <= '9'){
                    hash[board[j][i]-'0']++;
                }
            }
            for(int i = 0;  i < 10; i++){
                if(hash[i] > 1)
                    return false;
            }
        }
        vector<int> hash1(10, 0);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash1[board[i][j]-'0']++;
                }     
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash1[i] > 1)
                return false;
        }
        vector<int> hash2(10, 0);
        for(int i = 0; i < 3; i++){
            //vector<int> hash(10, 0);
            for(int j = 3; j < 6; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash2[board[i][j]-'0']++;
                }     
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash2[i] > 1)
                return false;
        }
        vector<int> hash3(10, 0);
        for(int i = 0; i < 3; i++){
            //vector<int> hash(10, 0);
            for(int j = 6; j < 9; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash3[board[i][j]-'0']++;
                }   
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash3[i] > 1)
                return false;
        }
        vector<int> hash4(10, 0);
        for(int i = 3; i < 6; i++){
            //vector<int> hash(10, 0);
            for(int j = 0; j < 3; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash4[board[i][j]-'0']++;
                }   
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash4[i] > 1)
                return false;
        }
        vector<int> hash5(10, 0);
        for(int i = 3; i < 6; i++){
            //vector<int> hash(10, 0);
            for(int j = 3; j < 6; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash5[board[i][j]-'0']++;
                }   
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash5[i] > 1)
                return false;
        }
        vector<int> hash6(10, 0);
        for(int i = 3; i < 6; i++){
            //vector<int> hash(10, 0);
            for(int j = 6; j < 9; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash6[board[i][j]-'0']++;
                }   
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash6[i] > 1)
                return false;
        }
        vector<int> hash7(10, 0);
        for(int i = 6; i < 9; i++){
            //vector<int> hash(10, 0);
            for(int j = 0; j < 3; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash7[board[i][j]-'0']++;
                }   
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash7[i] > 1)
                return false;
        }
        vector<int> hash8(10, 0);
        for(int i = 6; i < 9; i++){
            //vector<int> hash(10, 0);
            for(int j = 3; j < 6; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash8[board[i][j]-'0']++;
                }   
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash8[i] > 1)
                return false;
        }
        vector<int> hash9(10, 0);
        for(int i = 6; i < 9; i++){
            for(int j = 6; j < 9; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    hash9[board[i][j]-'0']++;
                }  
            }
        }
        for(int i = 0;  i < 10; i++){
            if(hash9[i] > 1)
                return false;
        }
        return true;
    }
};