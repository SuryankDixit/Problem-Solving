
#include<bits/stdc++.h>
using namespace std;

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
    
    void merge_two_lists(ListNode* dummy,ListNode* l2){
        ListNode* l1 = dummy->next;
        if(l1&&!l2)
            return ;
        if(l2&&!l1){
            dummy->next = l2;
            return ;
        }
        ListNode* temp=dummy;
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
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return nullptr;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = lists[0];
        for(int i=1;i<n;i++){
            merge_two_lists(dummy,lists[i]);
        }
        return dummy->next;
    }
};