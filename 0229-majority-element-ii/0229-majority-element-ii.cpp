class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        int maj1 = 0, maj2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maj1)
                cnt1++;
            else if(nums[i] == maj2)
                cnt2++;
            else if(cnt1 == 0){ 
                maj1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){ 
                maj2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int num: nums){
            if(num == maj1) cnt1++;
            else if(num == maj2) cnt2++;
        }

        if(cnt1 > nums.size()/3) res.push_back(maj1);
        if(cnt2 > nums.size()/3) res.push_back(maj2);

        return res;
    }
};