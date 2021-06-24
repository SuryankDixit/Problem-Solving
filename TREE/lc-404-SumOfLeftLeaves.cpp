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
    
    void solve(TreeNode* root){
        if(root==nullptr)
            return ;
        if(root->left && !root->left->left && ! root->left->right){
            ans+=root->left->val;
            solve(root->right);
            return;
        }else{
            solve(root->left);
            solve(root->right);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr)
            return 0;
        solve(root);
        return ans;
    }
};
