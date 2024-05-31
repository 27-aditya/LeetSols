class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        for(auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        stack<string> st;
        st.push("JFK");
        vector<string> itinerary;

        while (!st.empty()) {
            string currAP = st.top();
            if (graph.find(currAP) != graph.end() && !graph[currAP].empty()) {
                st.push(graph[currAP].top());
                graph[currAP].pop();
            } else {
                itinerary.push_back(currAP);
                st.pop();
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
