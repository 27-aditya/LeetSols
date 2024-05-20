class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int subtotal = 0;
        for(int num : nums)
            subtotal |= num;

        return subtotal << (nums.size()-1);
    }
};