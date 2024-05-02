class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        vector<pair<int, int>> sorted(mpp.begin(), mpp.end());
        sort(sorted.begin(), sorted.end(), [](const auto& left, const auto& right){
            return left.second > right.second;
        });

        vector<int>result;
        for(int i = 0 ; i < k && i < sorted.size(); i++){
            result.push_back(sorted[i].first);
        }
        return result;
    }
};