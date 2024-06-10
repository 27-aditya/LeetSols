class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for(auto iter : s){
            if(iter == '#'){
                if(!s1.empty()){
                    s1.pop_back();
                }
            }
            else
                s1.push_back(iter);
        }
        for(auto iter : t){
            if(iter == '#'){
                if(!s2.empty()){
                    s2.pop_back();
                }
            }
            else
                s2.push_back(iter);
        }
        return s1==s2;
    }
};