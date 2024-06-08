class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(matrix[mid][0] <= target && matrix[mid].back() >= target){
                int left = 0;
                int right = m-1;
                while(left <= right){
                    int midd = (right+left)/2;
                    if(matrix[mid][midd] == target)
                        return true;    
                    else if(matrix[mid][midd] > target)
                        right = midd-1;
                    else 
                        left = midd+1;
                }
                return false;
            }else if(matrix[mid][0] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
};