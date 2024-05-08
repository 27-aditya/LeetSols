class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxcount = 0;
        vector<int> count(26);
        int i = 0;
        int j = 0;
        int result = 0;
        while(j < s.size()){
            count[s[j]-'A']++;
            maxcount = max(maxcount, count[s[j]-'A']);
            if(j-i+1-maxcount > k){
                count[s[i]-'A']--;
                i++;
            }
            result = max(j-i+1, result);
            j++;
        }
        return result;
    }
};