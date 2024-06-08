class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>map;
        map[0] = -1;
        int currsum = 0;
        for(int i = 0; i < n; i++){
            currsum += nums[i];
            int remainder = currsum%k;
            if(map.find(remainder) != map.end()){
                if(i - map[remainder] >= 2)
                    return true;
            }
            else
                map[remainder] = i;
        }
        return false;
    }
};