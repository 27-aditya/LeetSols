class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        unordered_map<int, vector<int>>map;
        vector<int>indegree(n);
        for(auto edge : edges){
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        vector<int>res;

        queue<int>leaf;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 1)
                leaf.push(i);
        }

        int remainingnode = n;
        while(remainingnode > 2){
            int leafcnt = leaf.size();
            remainingnode -= leafcnt;

            for(int i = 0; i < leafcnt; i++){
                int leav = leaf.front();
                leaf.pop();
                for(int neighbour : map[leav]){
                    if(--indegree[neighbour] == 1)
                        leaf.push(neighbour);
                }
            }
        }

        while(!leaf.empty()){
            res.push_back(leaf.front());
            leaf.pop();
        }
        return res;
    }
};