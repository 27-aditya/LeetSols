class Solution {
public:
    bool isPalindrome(string s) {
        string anew;
        int i = 0;
        int k = 0;
        int j = 0;
        for(char c:s){
            if(isalnum(c)){
                anew += tolower(c);
            }
        }
        while(j < anew.length()/2){
            if(tolower(anew[j]) != tolower(anew[anew.size()-j-1]))
                return false;
            j++;
        }
        return true;
    }
};