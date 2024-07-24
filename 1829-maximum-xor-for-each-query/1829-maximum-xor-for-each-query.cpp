class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxnum = pow(2, maximumBit)-1;
        vector<int>prefix(n, 0);
        int cnt;
        for(int i = 0; i < n; i++){
            if(i == 0)
                cnt = 0;
            else 
                cnt = prefix[i-1];
            prefix[i] = nums[i]^cnt;
        }

        vector<int>res;
        for(int i = n-1; i >= 0; i--){
            res.push_back(maxnum^prefix[i]);
        }

        return res;
    }
};