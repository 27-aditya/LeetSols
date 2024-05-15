class node{
public:
    node* children[26];
    bool isword;

    node(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isword = false;
    }
};
class WordDictionary {
private:
    node* root;

    bool searchinnode(string& word, int i, node* tnode){
        if(tnode == NULL)
            return false;
        if(i == word.size())
            return tnode->isword;
        if(word[i] != '.') {
            return searchinnode(word, i + 1, tnode->children[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++)
            if (searchinnode(word, i + 1, tnode->children[j]))
                return true;
        return false;
    }
public:
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* tnode = root;
        int curr = 0;
        for(int i = 0; i < word.size();  i++){
            curr = word[i]-'a';
            if(tnode->children[curr] == NULL)
                tnode->children[curr] = new node();
            tnode = tnode->children[curr];
        }
        tnode->isword = true;
    }
    
    bool search(string word) {
        node* tnode = root;
        return searchinnode(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */