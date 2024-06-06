class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq; // dist, num
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int dist = abs(arr[i]-x);
            pq.push({dist, arr[i]});
            if(i >= k)
                pq.pop();
        }
        vector<int>res;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};