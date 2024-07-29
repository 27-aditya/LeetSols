class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;

        for(auto ch : columnTitle){
            int letter = ch-'A'+1;
            res = res*26 + letter;
        }

        return res;
    }
};