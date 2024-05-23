class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int n = s.size();
        unordered_map<char, int> m;
        for(int i = 0; i < n; i++){
            m[s[i]] = i;
        }   

        int l = 0;
        int r = 0;
        int lastof = m[s[l]];
        while(r < n){
            if(r == lastof){
                result.push_back(r-l+1);
                l = r+1;
                lastof = m[s[l]];
            }
            else if(r < lastof && m[s[r]] > lastof){
                lastof = m[s[r]];
            }
            r++;
        } 
        return result;
    }
};