class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol(2, -1);
        int sol1, sol2;
        int key;
        int found = 0;
        unordered_map<int, int> hash;
        for (int j = 0; j < nums.size(); j++) {
            hash[nums[j]] = j;
        }
        for (int i = 0; i < 10000; i++) {
            key = target - nums[i];
            if (hash.find(key) != hash.end() && hash[key] != -1) {
                if(i != hash[key]){     
                    sol1 = i;
                    sol2 = hash[key];
                    break;
                }
                else 
                    continue;
            }
        }
        sol[0] = sol1;
        sol[1] = sol2;
        return sol;
    }
};