class Solution {
public:
    int search(vector<int>& nums, int target) {
        int dist = -1;
        auto it = find(nums.begin(), nums.end(), target);
        dist = distance(nums.begin(), it);
        if(dist == nums.size())
            return -1;
        return dist;
    }
};