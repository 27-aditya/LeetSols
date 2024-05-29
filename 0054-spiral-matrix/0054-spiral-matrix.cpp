class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int cnt = row*col;
        vector<int> ans;
        int i  = 0;
        int j = 0;
        int rowmax = row-1;
        int colmax = col-1;
        int rowmin = 0;
        int colmin = 0;

        while(cnt > 0){ 
            for(j = colmin; j <= colmax && cnt > 0; ++j){
                ans.push_back(matrix[rowmin][j]);
                cnt--;
            }
            rowmin++;
            for(i = rowmin; i <= rowmax && cnt > 0; ++i){
                ans.push_back(matrix[i][colmax]);
                cnt--;
            }
            colmax--;
            for(j = colmax; j >= colmin && cnt > 0; --j){
                ans.push_back(matrix[rowmax][j]);
                cnt--;
            }
            rowmax--;
            for(i = rowmax; i >= rowmin && cnt > 0; --i){
                ans.push_back(matrix[i][colmin]);
                cnt--;
            }
            colmin++;
        }

        return ans;
    }
};