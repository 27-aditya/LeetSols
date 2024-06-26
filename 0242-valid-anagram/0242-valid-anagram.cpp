class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[50000] = {0};
        int arr2[50000] = {0}; 
        for(int i = 0; i < s.length(); i++)
            arr1[s[i]-'0']++;
        
        for(int i = 0; i < t.length(); i++)
            arr2[t[i]-'0']++;

        for(int i = 0; i < 50000; i++){
            if(arr1[i] != arr2[i])
                return false;
            else 
                continue;
        }
        return true;
    }
};