class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        int n = details.size();
        for(int i = 0; i < n; i++){
            string str = details[i];
            int len = str.length();
            int index = 0;
            while(str[index] >= '0' && str[index] <= '9')
                index++;
            index++;
            int age = stoi(str.substr(index, 2));
            if(age > 60)
                res++;
        }
        return res;
    }
};