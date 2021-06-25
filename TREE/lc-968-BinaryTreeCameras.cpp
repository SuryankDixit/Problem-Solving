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
    
    int solve(TreeNode* root){
        if(!root)
            return 2;           // node is covered from its parent;
        
        if(!root->left && !root->right)
            return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        if(l==0 || r==0){
            ans++;
            return 1;
        }
        if(l==1 || r==1)
            return 2;
        else
            return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root)
            return 0;
        int c = solve(root);
        if(c<1)
            return ans+1;
        return ans;
    }
};
