class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> indegree(n, 0);

        for (vector<int>& edge : roads) {
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        sort(indegree.begin(), indegree.end());

        long long val = 1;
        long long res = 0;
        for (long long deg : indegree) {
            res += (val * deg);
            val++;
        }

        return res;
    }
};