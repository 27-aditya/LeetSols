class Solution {
public:
    int findMaxLength(vector<int>& nums) {  
        unordered_map<int,int>map;
        map[0] = -1;
        int maxlength = 0;
        int cnt = 0;
    
        for(int i = 0; i < nums.size(); i++){
            cnt += (nums[i] == 1) ? 1 : -1;
            if(map.find(cnt) != map.end())
                maxlength = max(maxlength, i - map[cnt]);
            else
                map[cnt] = i;
        }
        return maxlength;
    }
};