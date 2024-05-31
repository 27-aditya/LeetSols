class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < flights.size(); i++){
            int src = flights[i][0];
            int dest = flights[i][1];
            int cost = flights[i][2];
            adj[src].push_back({dest, cost});
        }  
        vector<int>time(n, 1e9);
        time[src] = 0;
        queue<pair<int, pair<int,int>>>q;
        // stops, src, dist
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto iter = q.front();
            q.pop();
            int stops = iter.first;
            int currnode = iter.second.first;
            int dist = iter.second.second;

            if(stops > k) continue;

            for(int i = 0; i < adj[currnode].size(); i++){
                auto it = adj[currnode][i];
                int node = it.first;
                int cost = it.second;

                if(time[node] > dist+cost && stops <= k){
                    time[node] = dist+cost;
                    q.push({stops+1,{node, dist+cost}});
                }
            }
        }

        if(time[dst] == 1e9) return -1;
        return time[dst];
    }
};