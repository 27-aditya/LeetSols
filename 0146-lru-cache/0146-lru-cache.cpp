class Node{
public:
    int k;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int value){
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }

};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);

        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(hash.find(key) != hash.end()){
            remove(hash[key]);
            insert(hash[key]);
            return hash[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            remove(hash[key]);
            delete hash[key];
        }
        hash[key] = new Node(key, value);
        insert(hash[key]);

        if(hash.size() > cap){
            Node *leftn = left->next;
            remove(leftn);
            hash.erase(leftn->k);

            delete leftn;
        }
    }
private:
    unordered_map<int, Node*>hash;
    Node* left;
    Node* right;
    int cap;

    void remove(Node *node){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node *prev = right->prev;
        Node *next = right;

        prev->next = node;
        right->prev = node;

        node->prev = prev;
        node->next = right;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */