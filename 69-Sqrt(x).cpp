class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;

        int l = 1;
        int r = x;
        long long mid = -1;
        while(l <= r){
            mid = l + (r-l)/2;

            long long square = mid*mid;
            if(square > x){
                r = mid-1;
            }
            else if(square == x)
                return mid;
            else{
                l = mid+1;
            }
        }
        return static_cast<int>(round(r));
    }
};