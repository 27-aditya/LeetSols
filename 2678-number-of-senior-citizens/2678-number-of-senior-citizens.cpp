class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        int n = details.size();
        for(int i = 0; i < n; i++){
            int age=( (details[i][11]-'0')*10 )+(details[i][12]-'0');
            if(age > 60)
                res++;
        }
        return res;
    }
};