class Solution {
private:
    bool ispermutation(vector<int> hash){
        for(int i = 0; i < 26;i++){
            if(hash[i] != 0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m > n)
            return false;
        vector<int> hash(26);
        for(int i =0; i < m;i++){
            hash[s1[i]-'a']++;
            hash[s2[i]-'a']--;
        }
        if(ispermutation(hash)){
            return true;
        }

        for(int i = m; i < n; i++){
            hash[s2[i]-'a']--;
            hash[s2[i-m]-'a']++;
            if(ispermutation(hash))
                return true;
        }
        return false;
    }
};
