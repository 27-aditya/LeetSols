/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>map;
        Node* head1 = head;
        while(head1){
            map[head1] = new Node(head1->val);
            head1 = head1->next;
        }    
        head1 = head;
        while(head1){
            Node* newnode = map[head1];
            newnode->next = map[head1->next];
            newnode->random = map[head1->random];
            head1 = head1->next; 
        }
        return map[head];
    }
};