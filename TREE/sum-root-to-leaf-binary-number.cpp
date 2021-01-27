#include<bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root,int &res,int sum){
        if(root==nullptr)
            return ;
        
        sum=sum*2+root->val;
        if(root->left==nullptr && root->right==nullptr){
            res+=sum;
            return ;
        }
        dfs(root->left,res,sum);
        dfs(root->right,res,sum);
        return ;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int res=0;
        dfs(root,res,0);
        return res;
    }
};