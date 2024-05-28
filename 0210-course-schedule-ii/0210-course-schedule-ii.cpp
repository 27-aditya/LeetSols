class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto edge: prerequisites){
            indegree[edge[0]]++;
            adjlist[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i = 0; i < adjlist[node].size();i++){
                if(--indegree[adjlist[node][i]] == 0){
                    q.push(adjlist[node][i]);
                }
            }
            cnt++;
        }
        vector<int> empty;
        if (cnt != numCourses)
            return empty;
        return ans;
    }
};