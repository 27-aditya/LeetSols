class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if(s[0] == ')' || s[n-1] == '(')
            return false;

        int leftmin = 0;
        int leftmax = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                leftmin++;
                leftmax++;
                cout << leftmin << "  " << leftmax << endl;
            }
            else if(s[i] == '*'){
                if(leftmin-1 < 0)
                    leftmin = 0;
                else
                    leftmin--;
                leftmax++;
                cout << leftmin << "  " << leftmax << endl;
            }
            else if(s[i] == ')'){
                leftmax--;
                if(leftmin-1 < 0)
                    leftmin = 0;
                else
                    leftmin--;
                if(leftmax < 0)
                    return false;
                cout << leftmin << "  " << leftmax << endl;
            }
        }    
        
        if(min(leftmin, leftmax) == 0)
            return true;
        return false;
    }
};