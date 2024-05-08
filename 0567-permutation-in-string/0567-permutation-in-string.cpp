class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        int window = s1.size();
        int flag = 0;
        vector<int>hashs1(26);
        for(auto ch : s1)
            hashs1[ch-'a']++;
        for(int i = 0; i <= s2.size()-window; i++){
            vector<int>hashs2(26);
            int cnt = 0;
            for(int j = i; j < i + window; j++)
                hashs2[s2[j]-'a']++;
            for(int a = i; a < i + window; a++){
                if(hashs1[s2[a]-'a'] != hashs2[s2[a]-'a'])
                    break;
                else
                    cnt++;
            }
            if(cnt == window){
                flag = 1;
                break;
            }
        }
        if(flag)
            return true;
        return false;
    }
};
