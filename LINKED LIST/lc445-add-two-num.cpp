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
        
        stack<int> s1,s2;
        ListNode *p,*q;
        p=l1;q=l2;
        while(p){
            s1.push(p->val);
            p=p->next;
        }
        while(q){
            s2.push(q->val);
            q=q->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = nullptr;
        int c=0;
        while(!s1.empty()||!s2.empty()){
            int x,y,sum;
            x=y=sum=0;
            if(!s1.empty()){
                x=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                y=s2.top();
                s2.pop();
            }
            // cout<<x<<" "<<y<<" "<<c<<endl;
            sum=x+y+c;
            c=sum/10;
            curr = dummy->next;
            dummy->next = new ListNode(sum%10); 
            dummy->next->next = curr;
        }
        if(c>0){
            curr = dummy->next;
            dummy->next = new ListNode(c); 
            dummy->next->next = curr;
        }
        return dummy->next;
    }
};