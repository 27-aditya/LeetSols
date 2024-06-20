class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n, INT_MAX);
        distance[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> temp(distance);
            for(auto flight: flights){
                if(distance[flight[0]] != INT_MAX)
                    temp[flight[1]] = min(temp[flight[1]], distance[flight[0]]+ flight[2]);
            }
            distance = temp;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};