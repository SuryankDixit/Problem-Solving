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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* p,*q;
        p=l1,q=l2;
        int c=0;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(p||q){
            int x,y;
            x=0;y=0;
            if(p)   x=p->val;
            if(q)   y=q->val;
            int sum=(c+x+y);
            c=sum/10;
            curr->next = new ListNode(sum%10);
            curr=curr->next;
            if(p)   p=p->next;
            if(q)   q=q->next;
        }
        if(c>0)
            curr->next = new ListNode(c);
        return dummy->next;
    }
};