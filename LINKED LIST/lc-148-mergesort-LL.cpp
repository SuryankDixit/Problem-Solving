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
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy= new ListNode(-1);
        ListNode* curr =dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                curr->next = l1;
                l1=l1->next;
            }else{
                curr->next= l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1)
            curr->next=l1;
        else
            curr->next = l2;
        return dummy->next;
    }
    
    ListNode* getMiddle(ListNode* head){
        ListNode *slow,*fast,*prev;
        slow=fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        return slow;
    }
    
    ListNode* mergeSort(ListNode* head){
        // cout<<head->val<<" ";
        if(!head||!head->next)
            return head;
        
        
        ListNode* slow = getMiddle(head);
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(slow);
        return merge(left,right);
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        return mergeSort(head);        
    }
    
};