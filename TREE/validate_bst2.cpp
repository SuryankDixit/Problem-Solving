
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
    bool isValidBST(TreeNode* root) {
        
        bool status = dfs(root , LONG_MIN, LONG_MAX);
        return status;
    }
    
    bool dfs(TreeNode *root, long long min, long long max){
        
        if(root==NULL)
            return true;
        
        if(root->val <= min || root->val >= max)
            return false;
        
        bool l = dfs(root->left , min , root->val);
        bool r = dfs(root->right , root->val , max);
        if(l && r)
            return true;
        return false;
    }
};
