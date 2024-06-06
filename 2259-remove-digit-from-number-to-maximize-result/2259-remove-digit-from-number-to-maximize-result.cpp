class Solution {
public:
    string removeDigit(string number, char digit) {
        string maxnum = "";
        for(int i = 0; i < number.size(); i++){
            string temp = number;
            if(number[i] == digit)
                maxnum = max(temp.erase(i, 1), maxnum);
        }
        return maxnum;
    }
};