class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //set<int> st(nums.begin(), nums.end());
        if(nums.size() == 0)
            return nums.size();
        sort(nums.begin(), nums.end());
        int currcount = 1;
        int maxcount = 0;
        int i = 0;
        int a = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1])
                if(nums[i] == nums[i-1] + 1)
                    currcount++;
            else{
                maxcount = max(currcount, maxcount);
                currcount = 1;
            }
        }
        //cout << count[0]<< endl;
        return max(maxcount, currcount);
    }
};