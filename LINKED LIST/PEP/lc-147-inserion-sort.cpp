
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        
        ListNode* dummy = new ListNode(-2);
        ListNode* start = dummy;
        dummy->next = head;
        ListNode* end =head;
        ListNode* temp = head->next;
        dummy->next->next = nullptr;
        
        while(temp){
            ListNode* Next = temp->next;
            if(temp->val < end->val){
                cout<<temp->val<<endl;
                for(ListNode* x=start;x!=end;){
                    if(x->next->val > temp->val){
                        temp->next = x->next;
                        x->next = temp;
                        break;
                    }
                    x=x->next;
                }
            }else{
                temp->next = nullptr;
                end->next = temp;
                end = end->next;
            }
            temp =Next;
        }
        return dummy->next;
    }
};