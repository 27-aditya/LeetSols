class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int currsum = 0;
        int cnt = 0;
        map[0] = 1;

        for(int num:nums){
            currsum += num;
            if(map.find(currsum-k) != map.end())
                cnt += map[currsum-k];
            map[currsum]++;
        } 
        return cnt;
    }
};