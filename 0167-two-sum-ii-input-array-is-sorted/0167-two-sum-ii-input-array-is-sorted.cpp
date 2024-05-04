class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,0);
        multiset<int> ms;
        for(auto num : numbers){
            ms.insert(num);
        }
        for(int i = 0; i < numbers.size(); i++){
            if(ms.count(target - numbers[i]) > 0){
                result[1] = i+1;
                auto it = ms.find(target-numbers[i]);
                int index = distance(ms.begin(),  it);
                result[0] = index+1;
            }
        }
        return result;
    }
};