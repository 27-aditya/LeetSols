class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cap = n/3;
        vector<int>res;
        unordered_map<int,int>hash;

        for(int num : nums){ 
            hash[num]++;
            if(hash[num] > cap && find(res.begin(), res.end(), num) == res.end()) res.push_back(num);
        }

        return res;
    }
};