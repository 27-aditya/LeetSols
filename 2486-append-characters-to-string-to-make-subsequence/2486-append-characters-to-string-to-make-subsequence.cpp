class Solution {
public:
    int appendCharacters(string s, string t) {
        int cnt = 0;
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        for(i = 0 ;i < n && j < m ; i++){
            if(s[i] == t[j])
                j++;
        }
        
        return m-j;
    }
};