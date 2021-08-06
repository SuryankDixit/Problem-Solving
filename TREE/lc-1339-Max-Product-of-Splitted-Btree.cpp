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
    
    long ans=0;
    long sum=0;
    long mod=1e9+7;
    
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int total = l+r+root->val;
        ans=max(ans,(sum-total)*total);
        return total;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        sum = dfs(root);
        dfs(root);
        return ans%mod;
    }
};