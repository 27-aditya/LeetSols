class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        vector<int>result;
        deque<int>d;
        while(r < nums.size()){
            while(!d.empty() && nums[d.back()] < nums[r])
                d.pop_back();
            
            d.push_back(r);

            if(l > d.front())
                d.pop_front();
            
            if(r+1 >= k){ 
                result.push_back(nums[d.front()]);
                l++;
            }
            r++;
        }
        return result;
    }
};