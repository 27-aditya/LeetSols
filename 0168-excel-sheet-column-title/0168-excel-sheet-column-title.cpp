class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0){
            int rem = n % 26;

            if(rem == 0){
                res += 'Z';
                n = n/26-1;
            }
            else{
                res += 'A' +rem-1;
                n = n/26;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};