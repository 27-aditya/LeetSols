/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* prevtemp = NULL;
        int total = 1;
        while(temp->next != NULL){
            //cout << total << endl;
            total++;
            prevtemp = temp;
            temp = temp->next;
        }
        //cout << total << endl;
        int frontn = total-n+1;
        //cout << frontn << endl;
        if(n == 1){
            prevtemp->next = NULL;
            return head;
        }
        if(frontn == 1){
            head = head->next;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i = 0; i < frontn-1; i++){
            prev = curr;
            curr = curr->next;
        }
        cout << prev->val << endl;
        cout << curr->val << endl; 
        prev->next = curr->next;
        return head;
    }
};