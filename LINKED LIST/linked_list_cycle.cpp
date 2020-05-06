
/*
141. Linked List Cycle
*/

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
    bool hasCycle(ListNode *head) {
       
       // this solution does not uses any extra space
        if(head==NULL)
            return false;
        if(head->next==NULL)
            return false;
        
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp2!=NULL)
        {
            temp1=temp1->next;
            if(temp2->next && temp2->next->next)
                temp2=temp2->next->next;
            else
                return false;
            if(temp1==temp2)
                return true;
        }
        return false;


        // Uses O(n) extra space
        /*
         ListNode* temp=head;
        unordered_set<ListNode*> s;
        int index=0;
        while(temp!=NULL)
        {
            if(s.find(temp)!=s.end())
                return true;
            s.insert(temp);
            temp=temp->next;
        }
        return false;
        */
    }
};