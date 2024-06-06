class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [&](int a, int b){
            return ((to_string(a)+to_string(b)) > (to_string(b)+to_string(a)));
        };

        sort(nums.begin(), nums.end(), cmp);
        string res = "";

        for(auto num : nums){
            res += to_string(num);
        }
        return res[0] == '0' ? "0" : res;
    }
};