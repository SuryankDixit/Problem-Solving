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
    ListNode* oddEvenList(ListNode* head) {
        
        if( head==NULL)
            return head;
        ListNode* temp_even=head;
        if(head->next==NULL)
            return head;
        ListNode* temp_odd=head->next;
        ListNode* temp1=temp_even;
        ListNode* temp2=temp_odd;
        while(temp2!=NULL && temp2->next!=NULL)
        {
            temp1->next=temp2->next;
            temp1=temp1->next;
            temp2->next=temp1->next;
            temp2=temp2->next;
        }
        temp1->next=temp_odd;
        return temp_even;
    }
};
