class Solution {
private:
    struct floatvector{
        float value;
        vector<int> vc;
    };
    struct comparepair{
        bool operator()(const floatvector &a, const floatvector &b){
            return a.value > b.value;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<floatvector, vector<floatvector>, comparepair>pq;
        vector<vector<int>>result;
        for(int i = 0; i < points.size(); i++){
            float dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({dist, points[i]});
        }    
        for(int i = 0; i < k; i++){
            result.push_back(pq.top().vc);
            pq.pop();
        }
        return result;
    }
};