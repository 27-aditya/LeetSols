class Solution {
private:
    int happySum(int n){
        int sum = 0;
        while(n > 0){
            sum += pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = happySum(n);

        while(slow != fast && fast != 1){
            slow = happySum(slow);
            fast = happySum(happySum(fast));
        }    

        if(fast == 1)
            return true;
        return false;
    }
};