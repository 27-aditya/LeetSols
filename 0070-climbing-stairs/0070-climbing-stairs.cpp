class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n==2)
            return n;
        
        int first = 1;
        int second = 2;
        int result = 0;

        for(int i = 2; i < n;i++){
            result = first+second;
            first = second;
            second = result;
        }
        return result;
    }
};