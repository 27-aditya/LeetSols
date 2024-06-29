class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>res(n);

        for(auto edge: edges)
            map[edge[0]].push_back(edge[1]);
    
        for(int ancestor = 0; ancestor < n; ancestor++){
            for(auto node : map[ancestor])
                dfs(res, ancestor, node);
        }

        return res;
    }
private:
    unordered_map<int, vector<int>>map;
    void dfs(vector<vector<int>>&res, int i, int node){
        if(find(res[node].begin(), res[node].end(), i) != res[node].end())  return;
        
        res[node].push_back(i);
        for(auto child : map[node])
            dfs(res, i, child);
    }
};