#include<bits/stdc++.h>


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* l=lowestCommonAncestor(root->left, p, q);
        TreeNode* r=lowestCommonAncestor(root->right, p, q);
        

        // both left and right child returned some value, which means 
        if(l&&r)
            return root;
        
        if(!l)
            return r;
        return l;
    }
};