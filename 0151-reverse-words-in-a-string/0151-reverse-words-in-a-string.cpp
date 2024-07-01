class Solution {
public:
    string reverseWords(string s) {
        vector<string>res;
        int i = 0;
        int j = s.size()-1;

        while(s[i] == ' ')
            i++;

        while(s[j] == ' ')
            j--;

        cout << i << endl;
        cout << j << endl;

        string word = "";
    
        for(int a = i; a < j+1; a++){
            if(isalnum(s[a]))
                word += s[a];
            else{
                if(word != "")
                    res.push_back(word);
                word = "";
            }
        }
        res.push_back(word);

        reverse(res.begin(), res.end());
        string result = "";
        for(auto word : res)
            result += word + " ";

        return result.substr(0, result.size()-1);
    }
};