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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int cnt = k;
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* temp = NULL;
        while(curr != NULL){
            if(cnt > 1){
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;

                cnt--;
            }
            else{
                prev = curr;
                curr = curr->next;
                cnt = k;

                ListNode* end = curr;
                for(int i = 0; i < k; i++){
                    if(end == NULL)
                        return dummy->next;
                    end = end->next;
                }
            }
        }
        return dummy->next;
    }
};