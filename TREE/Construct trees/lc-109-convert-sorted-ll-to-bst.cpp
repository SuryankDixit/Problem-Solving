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

  //Definition for a binary tree node.
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    
    TreeNode* make_tree(vector<int> &v,int l,int r){
        if(l>r)
            return nullptr;
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(v[mid]);
        // cout<<root->val<<endl;
        if(l==r)
            return root;
        root->left = make_tree(v,l,mid-1);
        root->right = make_tree(v,mid+1,r);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        
        vector<int> v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        return make_tree(v,0,v.size()-1);
    }
};