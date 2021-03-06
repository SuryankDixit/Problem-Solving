//112. Path Sum Leetcode

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
    bool hasPathSum(TreeNode* root, int sum) {
         if (root == NULL) { return false; }
        sum -= root->val;
        cout<<root->val;
        if (root->left == NULL && root->right == NULL && sum == 0) { return true; }
        if (root->left  != NULL) { if (hasPathSum(root->left,  sum)) { return true; } }
        if (root->right != NULL) { if (hasPathSum(root->right, sum)) { return true; } }
        return false;
    }
};
