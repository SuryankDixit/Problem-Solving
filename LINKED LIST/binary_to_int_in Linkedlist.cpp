
/*
1290. Convert Binary Number in a Linked List to Integer
*/

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
    int getDecimalValue(ListNode* head) {
        
        /*ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        int result=0;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->val==1)
                result=result+(1<<(count-1));
            count--;
            temp=temp->next;
        }
        return result;*/
        int num = 0;
        while(head) {
            num = (num << 1) + head->val;
            head = head->next;
        }
        return num;
 
    }
};