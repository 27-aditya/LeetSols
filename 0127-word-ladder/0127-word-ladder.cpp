class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for(int i = 0; i< wordList.size(); i++)
            set.insert(wordList[i]);

        queue<string> q;
        q.push(beginWord);
        int re = 1;

        while(!q.empty()){
            int cnt = q.size();
            for(int i = 0; i< cnt; i++){
                string word = q.front();
                q.pop();

                if(word == endWord)
                    return re;

                set.erase(word);

                for(int j  = 0; j < word.size() ;j++){
                    char c = word[j];
                    for(int k = 0; k < 26; k++){
                        word[j] = k + 'a';
                        if(set.find(word) != set.end()){
                            q.push(word);
                            set.erase(word);
                        }
                        word[j] = c;
                    }
                }
            }
            re++;
        }
        return 0;
    }
};