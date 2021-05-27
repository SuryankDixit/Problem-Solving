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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode* slow,*fast;
        slow=fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *prev = nullptr, *curr = slow->next, *Next;
        while(curr!=nullptr){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=Next;
        }
        slow->next=prev;
    
        fast=slow->next;
        prev=head;
        ListNode* d = new ListNode(-1);
        ListNode* t=d;
        
        while(fast!=nullptr){
            t->next=prev;
            prev=prev->next;
            t->next->next = fast;
            fast=fast->next;
            t=t->next->next;
        }
        while(prev!=slow->next){
            t->next=prev;
            prev=prev->next;
            t=t->next;
        }
        t->next = nullptr;
        return ;
    }
};