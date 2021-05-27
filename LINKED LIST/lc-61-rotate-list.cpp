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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        
        ListNode* temp = head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }
        k = k%cnt;
        
        ListNode* d = new ListNode(-1);
        ListNode* fast = d;
        ListNode* slow = d;
        d->next = head;
        while(k--)
            fast = fast->next;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next;
        }
        // cout<<slow->val<<" "<<fast->val;
        fast->next = head;
        d->next = slow->next;
        slow->next = nullptr;
        return d->next;
    }
};