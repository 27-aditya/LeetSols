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
    int getLen(ListNode* head){
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getLen(head);
        if(head == NULL|| k > n)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* buffer = curr->next;
        int cnt = 0;
        while(cnt < k){
            buffer = curr->next;
            curr->next = prev;
            prev = curr;
            curr = buffer;
            cnt++;
        }
        if(buffer != NULL)
            head->next = reverseKGroup(buffer,k);
        return prev; 
    }
};