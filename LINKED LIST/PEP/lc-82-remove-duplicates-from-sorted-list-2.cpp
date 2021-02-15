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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* d = new ListNode(-1);
        ListNode* t = d;
        ListNode* cur = head;
        while(cur && cur->next!=nullptr){
            if(cur->next->val != cur->val){
                t->next = cur;
                t=t->next;
            }else{
                while(cur->next && cur->next->val==cur->val)
                    cur = cur->next;
            }
            cur = cur->next;
        }
        t->next = cur;
        return d->next;
    }
};