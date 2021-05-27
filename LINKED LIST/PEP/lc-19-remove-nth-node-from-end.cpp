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
        if(head==nullptr)
            return head;
        
        ListNode* d = new ListNode(-1);
        ListNode* fast = d;
        ListNode* slow = d;
        d->next=head;

        while(n--)
            fast=fast->next;
        
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return d->next;
    }
};