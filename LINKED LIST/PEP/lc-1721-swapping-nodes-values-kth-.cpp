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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr)
            return head;
        
        ListNode* d = new ListNode(-1);
        ListNode* slow=d;
        ListNode* fast=d;
        d->next = head;
        ListNode* start;
        while(k--)
            fast=fast->next;
        start = fast;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        swap(start->val,slow->next->val);
        return head;
    }
};