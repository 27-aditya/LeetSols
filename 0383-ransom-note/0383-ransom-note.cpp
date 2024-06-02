class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;
        for(char ch : ransomNote){
            map[ch]++;
        }
        for(char ch : magazine){
            if(map.find(ch) != map.end())
                map[ch]--;
        }
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second > 0)
                return false;
        }
        return true;
    }
};