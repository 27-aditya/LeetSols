class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>map;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            map[nums[i]]++;
        }

        int limit = n/3;
        unordered_set<int>re;
        for(int num : nums){
            if(map[num] > limit)
                re.insert(num);
        }
        vector<int>res(re.begin(), re.end());
        return res;
    }
};