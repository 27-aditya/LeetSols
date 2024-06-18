class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>>map;
        int n = routes.size();
        for(int route = 0; route < n; route++){
            for(auto stop : routes[route]){
                map[stop].push_back(route);
            }
        }
    
        int cnt = 1;
        queue<int>q;
        unordered_set<int>set;

        for(auto route: map[source]){ 
            q.push(route);
            set.insert(route);
        }

        while(q.size()){
            int size = q.size();
            for(int i = 0; i < size; i++){ 
                int route = q.front();
                q.pop();
        
                for(auto stop : routes[route]){
                    if(stop == target)
                        return cnt;
                    
                    for(auto nroute : map[stop]){
                        if(!set.count(nroute)){
                            set.insert(nroute);
                            q.push(nroute);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};
