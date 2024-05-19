class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()  == 1)
            return stones[0];
        priority_queue<int>pq;
        for(int i = 0; i < stones.size(); i++)
            pq.push(stones[i]);
        
        int res = 0;

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x > y)
                pq.push(x-y);
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};