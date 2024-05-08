class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(auto ch: t)
            m[ch]++;

        int i = 0;
        int j = 0;
        int counter = t.size();

        int minstart = 0;
        int minlength = INT_MAX;

        while(j < s.size()){
            if(m[s[j]] > 0)
                counter--;
            
            m[s[j]]--;
            j++;

            while(counter == 0){
                if(j-i < minlength){
                    minstart = i;
                    minlength = j-i;
                }
                m[s[i]]++;
                if(m[s[i]] > 0)
                    counter++;
                i++;
            }
        }

        if(minlength != INT_MAX){
            return s.substr(minstart, minlength);
        }
        return "";
    }
};