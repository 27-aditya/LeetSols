class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,0);
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                result[0] = i+1;
                result[1] = j+1;
                break;
            }
            else if(numbers[i] + numbers[j] < target)
                i++;
            else if(numbers[i] + numbers[j] > target)
                j--;
        }
        return result;
    }
};