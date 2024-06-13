class TrieNode{
public:
    TrieNode* children[26];
    bool isword;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isword = false;
    }
};

class Solution {
public:
    void insert(string word, TrieNode* root){
        TrieNode* node = root;
        int curr = 0;
        for(int j = 0; j < word.size(); j++){
            curr = word[j]-'a';
            if(node->children[curr] == NULL)
                node->children[curr] = new TrieNode();
            node = node->children[curr];
        }
        node->isword = true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = "";
        TrieNode* root = new TrieNode();

        for(auto word : strs)
            insert(word, root);

        TrieNode* node = root;
        while(node){
            int childcnt = 0;
            int index = -1;
            for(int i = 0; i < 26; i++){
                if(node->children[i] != NULL){
                    childcnt++;
                    index = i;
                }
            }
            if(childcnt == 1 && !node->isword){
                res += index + 'a';
                node = node->children[index];
            }
            else
                break;
        }
        return res;
    }
};