class Solution {
private:
    string expandCenter(string s, int left, int right){
        while(left >= 0 && right <= s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        if(n == 1) return s;

        string res;
        for(int i = 0; i < n; i++){
            string even = expandCenter(s, i, i+1);
            if(even.size() > res.size())
                res = even;

            string odd = expandCenter(s, i, i);
            if(odd.size() > res.size()) 
                res = odd;
        }

        return res;
    }
};