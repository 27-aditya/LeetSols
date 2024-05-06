class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            if(target >= matrix[i][0] && target <= matrix[i].back()){
                for(int j = 0; j < matrix[i].size();j++)
                    if(target == matrix[i][j])
                        return true;
            }
        }
        return false;
    }
};