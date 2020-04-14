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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp1;
        ListNode* temp2;
        temp1=head;
        temp2=head;
        
        while(temp2->next!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp2->next!=NULL)
                temp2=temp2->next;
        }
        return temp1;
    }
};
