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
    int ans=0;
    
    void countNodes(TreeNode* root,int Max){
        if(!root)
            return;
        countNodes(root->left,max(Max,root->val));
        countNodes(root->right,max(Max,root->val));
        if(Max<=root->val)
            ans++;
        return;
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        countNodes(root,INT_MIN);
        return ans;
    }
};
