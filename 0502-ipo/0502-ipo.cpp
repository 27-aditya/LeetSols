class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>pc;
        for(int i = 0; i < profits.size(); i++){
            pc.push_back({capital[i],profits[i]});
        }
        sort(pc.begin(), pc.end());
        int n = pc.size();
        int j = 0;
        priority_queue<int>pq;
        
        for(int i = 0; i < k; i++){
            while(j < n && pc[j].first <= w){
                pq.push(pc[j].second);
                j++;
            }

            if(pq.empty())
                break;

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};