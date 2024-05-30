class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        vector<bool>inMST(n, false);
        vector<int>mindist(n, INT_MAX);
        int edges = 0;
        mindist[0] = 0;

        while(edges < n){
            int minedge = INT_MAX;
            int currNode = -1;

            for(int i = 0; i < n;i++){
                if(!inMST[i] && minedge > mindist[i]){
                    minedge = mindist[i];
                    currNode = i;
                }
            }
            
            result+=minedge;
            inMST[currNode] = true;
            edges++;

            for(int i = 0; i < n; i++){
                int cost = abs(points[currNode][0]-points[i][0])+abs(points[currNode][1]-points[i][1]);
                if(!inMST[i] && mindist[i] > cost)
                    mindist[i] = cost;
            }
        }
        return result;
    }
};