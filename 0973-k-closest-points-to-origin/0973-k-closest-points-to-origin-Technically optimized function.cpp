class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>tuples;
        for(auto p: points){
            tuples.push_back({p[0]*p[0]+p[1]*p[1], p[0],p[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq(tuples.begin(), tuples.end());
        vector<vector<int>> result;
        while(k--){
            vector<int> point = pq.top();
            pq.pop();
            result.push_back({point[1], point[2]});
        }
        return result;
    }
};