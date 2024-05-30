class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;

        for (int i = 1; i <= n; i++) {
            int u = -1;
            int min = INT_MAX;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && dist[j] < min) {
                    min = dist[j];
                    u = j;
                }
            }

            if (u == -1) break;

            visited[u] = true;

            for (int v = 0; v < times.size(); v++) {
                if (times[v][0] == u) {
                    int nextNode = times[v][1];
                    int time = times[v][2];
                    if (!visited[nextNode] && dist[nextNode] > dist[u] + time) {
                        dist[nextNode] = dist[u] + time;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }

        return res;
    }
};
