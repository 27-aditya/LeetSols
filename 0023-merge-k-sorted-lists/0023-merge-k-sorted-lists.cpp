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
private:
    ListNode* merge2Lists(ListNode *l1, ListNode *l2){
        if(l1 == NULL && l2 == NULL)
            return NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        ListNode* head = NULL;
        if(l1->val <= l2->val){ 
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        ListNode *temp = head;

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1 == NULL)
            temp->next = l2;
        else
            temp->next = l1;
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        while(n > 1){
            for(int i = 0; i < n/2; i++){
                lists[i] = merge2Lists(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists.front();
    }
};