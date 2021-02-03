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
    ListNode* reverseList(ListNode* head) {
        ListNode* t1=head;
        ListNode* t2;
        ListNode* p = nullptr;
        while(t1!=nullptr){
            t2 = t1->next;
            t1->next = p;
            p = t1;
            t1 = t2;
        }
        head = p;
        return head;
    }
};