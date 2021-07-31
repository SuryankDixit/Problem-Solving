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
    
    bool check(TreeNode* root, TreeNode* sub){
        if(root==nullptr || sub==nullptr)
            return root==sub;
        if(root->val!=sub->val)
            return false;
        
        return check(root->left, sub->left) && check(root->right,sub->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr || subRoot==nullptr)
            return root==subRoot;
        
        if(root->val == subRoot->val){
            bool status = check(root,subRoot);
            if(status)
                return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};