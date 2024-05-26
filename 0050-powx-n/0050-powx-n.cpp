class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1)
            return 1;
        double res = 1;
        double curr = x;
        for(long i = abs(n); i > 0;i/=2){
            if(i %2 == 1)
                res *= curr;
            curr *= curr;
        }
        if(n < 0)
            return 1.0/res;
        return res;
    }
};