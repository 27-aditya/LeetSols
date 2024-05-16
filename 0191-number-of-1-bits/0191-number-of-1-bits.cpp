class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n > 0){
            int num = n&1;
            if(num == 1)
                cnt++;
            n = n>>1;
        }    
        return cnt;
    }
};