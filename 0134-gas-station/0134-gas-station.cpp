class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int totalgas = 0;
        int totalcost = 0;
        for(int i = 0; i < n; i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }
        if(totalcost > totalgas) return -1;
        int gc = 0;
        int startingpoint = 0;
        for(int i = 0; i < n; i++){
            gc += gas[i] - cost[i];
            if(gc < 0){
                gc = 0;
                startingpoint = i+1;
            }
        }
        return startingpoint;
    }
};