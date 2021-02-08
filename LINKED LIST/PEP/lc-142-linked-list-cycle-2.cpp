/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
         
    ListNode* slow=head;
    ListNode* fast=head;
        
    if(head==nullptr||head->next==nullptr)
    return nullptr;
        
    while(fast!=nullptr)
    {
        
        slow=slow->next;
        if(fast->next!=nullptr)
            fast=fast->next->next;
        else
        break;
        
        if(slow==fast)
            break;
        
    }
    if(slow==fast)
    {
        slow=head;
        //Node* prev=fast;
        while(slow!=fast)
        {
            slow=slow->next;
            //prev=fast;
            fast=fast->next;
            
            
        }
        //prev->next=nullptr;
        return slow;
    }
    return nullptr;
    
        
    }
};