class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
            continue;

            for(int j = 0;j < 3; j++){
                if(triplets[i][j] == target[j])
                    st.insert(j);
            }
        }
        if(st.size() == 3)
            return true;
        return false;
    }
};