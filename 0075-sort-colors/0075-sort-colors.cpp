class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>nu(3);
        for(auto num : nums){
            nu[num]++;
        }
        nums.clear();  
        for(int i = 0; i < 3; i++){
            while(nu[i] > 0){ 
                nums.push_back(i);
                nu[i]--;
            }
        }
    }
};