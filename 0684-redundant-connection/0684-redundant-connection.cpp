class Solution {
private:
    void unin(int u, int v, vector<int>&ast){
        int rootu = fid(u, ast);
        int rootv = fid(v, ast);
        if(rootu != rootv){ 
            if(ast[rootu] < ast[rootv]){
                ast[rootu] += ast[rootv];
                ast[rootv] = rootu;
            }
            else{
                ast[rootv] += ast[rootu];
                ast[rootu] = rootv;
            }
        }
    }

    int fid(int u, vector<int> &ast){
        if(ast[u] < 0) 
            return u;
        return ast[u] = fid(ast[u],ast);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>extraedge;
        vector<int> ast(n+1,-1);

        for(auto edge:edges){
            if(fid(edge[0], ast) == fid(edge[1],ast)) extraedge.push_back(edge);
            unin(edge[0],edge[1],ast);
        }

        return extraedge.back();
    }
};