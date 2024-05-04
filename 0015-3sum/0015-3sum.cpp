class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int i;
        int j;
        int k;
        for(i = 0 ; i < nums.size()-2; i++){
            j = i+1;
            k = nums.size()-1;
            while(j < k){
                if(nums[j] + nums[k] + nums[i] == 0){                    
                    st.insert({nums[i], nums[j], nums[k]});   
                    j++;
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
            }
        }
        for(auto s: st)
            result.push_back(s);
        return result;
    }
};