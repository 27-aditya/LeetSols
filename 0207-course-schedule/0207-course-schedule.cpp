class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjlist(numCourses);
        for(const auto& pair : prerequisites){
            int u = pair[0];
            int v = pair[1];
            indegree[u]++;
            adjlist[v].push_back(u);
        }  
        queue<int> q;

        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto neighbor : adjlist[node])
                if(--indegree[neighbor] == 0)
                    q.push(neighbor);

            cnt++;
        }
        if(cnt != numCourses)
            return false;
        return true;
    }
};