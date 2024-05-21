class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            if(result.empty() || result.back()[1] < intervals[i][0])
                result.push_back(intervals[i]);
            else{ 
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
        }
        return result;
    }
};