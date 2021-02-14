
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
            return head;
        
        ListNode* d= new ListNode(-1);
        d->next = head;
        ListNode* temp = d;
        while(temp->next!=nullptr && temp->next->next !=nullptr){
            ListNode* t1 = temp->next;
            ListNode* t2 = t1->next;
            t1->next = t2->next;
            t2->next = t1;
            temp->next=t2;
            temp=temp->next->next;
        }
        return d->next;
    }
};