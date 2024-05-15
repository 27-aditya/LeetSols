class Trie {
private:
    vector<string> trie;
    int size;
public:
    Trie() {
        size = 0;
    }
    
    void insert(string word) {
        trie.push_back(word);
        size++;
    }
    
    bool search(string word) {
        for(int i = 0; i < size; i++)
            if(trie[i] == word)
                return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(int i = 0; i < size; i++){
            if(trie[i].front() == prefix.front()){
                if(trie[i].size() >= prefix.size()){
                    int cnt = 0;
                    for(int j = 0; j < prefix.size(); j++){
                        if(trie[i][j]==prefix[j])
                            cnt++;
                    }
                    if(cnt == prefix.size())
                        return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */