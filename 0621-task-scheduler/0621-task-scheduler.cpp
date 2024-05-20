class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        int maxcnt = 0;
        int mfcnt = 0;

        for(char c: tasks)
            cnt[c-'A']++;
        
        for(int i = 0; i < 26; i++)
            maxcnt = max(maxcnt, cnt[i]);
        
        for(int i = 0; i < 26; i++)
            if(cnt[i] == maxcnt)
                mfcnt++;
        
        return max(int(tasks.size()), (maxcnt-1)*(n+1)+mfcnt);
    }
};