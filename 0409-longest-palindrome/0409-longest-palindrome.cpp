class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>map;
        int cnt = 0;
        int flag = 0;
        for(char ch : s)
            map[ch]++;

        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second %2 == 0)
                cnt += it->second;
            else if(it->second%2 == 1){ 
                cnt += it->second-1;
                flag = 1;
            }
        }
        if(flag == 1)
            return cnt+1;
        return cnt;
    }
};