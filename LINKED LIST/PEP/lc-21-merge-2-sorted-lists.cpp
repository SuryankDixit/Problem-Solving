#include<bits/stdc++.h>


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1&&!l2)
            return l1;
        if(l2&&!l1)
            return l2;
        
        ListNode* d = new ListNode(-1);
        ListNode* temp=d;
        while(l1 && l2){
            if(l1->val==l2->val){
                temp->next = l1;
                l1=l1->next;
                temp->next->next = l2;
                l2=l2->next;
                temp=temp->next->next;
            }else if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }else{
                temp->next=l2;
                l2=l2->next;
                temp = temp->next;
            }
        }
        while(l1){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2){
            temp->next=l2;
            l2=l2->next;
            temp = temp->next;
        }
        temp->next=nullptr;
        return d->next;
    }
};