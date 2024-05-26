class Solution {
public:
    int getSum(int a, int b) {
        double n1 =(double)pow(2, a);
        double n2 = (double)pow(2, b);
        double res = n1*n2;
        n1 = log(res)/log(2);
        return n1;
    }
};