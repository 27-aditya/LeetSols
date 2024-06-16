class Solution {
public:
    int minPatches(vector<int>& nums, int n){ 
        int cnt = 0;
        long long int sum = 1;
        int i = 0;

        while(sum <= n){
            if(i < nums.size() && nums[i] <= sum){
                sum += nums[i];
                i++;
            }
            else{
                sum += sum;
                cnt++;
            }
        }

        return cnt;
    }
};