class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.size();
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        long sum = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
           
            if (sum > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            sum = sum * 10 + digit;
            i++;
        }
        
        return (sign * sum);
    }
};