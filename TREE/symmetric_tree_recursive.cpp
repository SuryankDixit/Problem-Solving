//101. Symmetric Tree recursive

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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetric_helper(root->left,root->right);
    }
    bool isSymmetric_helper(TreeNode* root1, TreeNode* root2) {
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    if (root1->val != root2->val) return false;
    return isSymmetric_helper(root1->left, root2->right) && isSymmetric_helper(root1->right, root2->left);
}
};
