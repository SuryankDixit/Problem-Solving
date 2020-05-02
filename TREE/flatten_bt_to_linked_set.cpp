// 114. Flatten Binary Tree to Linked List

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        vector<TreeNode*> v;
        preorder(root,v);
        
        if(v.size()>1){
        TreeNode* temp=v[0];
        for(int i=1;i<v.size();i++)
        {
            TreeNode* temp1=v[i];
            temp->right=temp1;
            temp->left=NULL;
            temp=temp1;
        }
        }

    }
    void preorder(TreeNode* root, vector<TreeNode*> &v)
    {
        if(root==NULL)
            return;
        
        v.push_back(root);
        preorder(root->left,v);
        preorder(root->right,v);
    }
};
