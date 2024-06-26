class Trie{
public:
    Trie* children[26];
    bool isend;

    Trie(){
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        isend = false;
    }
};

class Solution {
private:
    Trie* root = new Trie();

    void insert(string word){
        Trie* node = root;
        for(char c : word){
            int i = c-'a';
            if(node->children[i] == nullptr)
                node->children[i] = new Trie();
            node = node->children[i];
        }
        node->isend = true;
    }

    string search(string word){
        Trie* node = root;
        string result;
        for(char c : word){
            int i = c-'a';
            if(node->children[i] == nullptr)
                return word;
            result += c;
            if(node->children[i]->isend)
                return result;
            node = node->children[i];
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string word : dictionary)
            insert(word);

        stringstream ss(sentence);
        string word, result;

        while(ss >> word){
            if(!result.empty())
                result += " ";
            result += search(word);
        }
        return result;
    }
};