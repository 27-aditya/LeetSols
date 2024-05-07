class Solution {
public:
    int findMin(vector<int>& nums) {
        int cnt = 0;
        int i;
        for( i = 0; i < nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                cnt = i+1;
                break;
            }
        }
        if(cnt == nums.size())
            return nums[0];
        return nums[cnt];
    }
};