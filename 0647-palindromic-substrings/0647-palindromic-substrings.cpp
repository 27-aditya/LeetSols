class Solution {
private:
    void expandCenter(string s, int left, int right, int& cnt){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            cnt++;
        }       
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 1) return 1;
        int cnt = 0;
        for(int i =0; i < n; i++){
            expandCenter(s, i, i, cnt);
            expandCenter(s, i, i+1, cnt);
        }
    return cnt;
    }
};