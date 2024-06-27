class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>set;
        int cnt = 1;
        
        for(char c : s){
            if(set.find(c) != set.end()){
                cnt++;
                set.clear();
            }
            set.insert(c);
        }
        return cnt;
    }
};