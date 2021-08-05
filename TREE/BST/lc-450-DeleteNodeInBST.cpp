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
    
    TreeNode* findMinInRightSubtree(TreeNode* root){
        while(root->left!=nullptr)
            root=root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        if(key < root->val)
            root->left = deleteNode(root->left,key);
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else{
            if(!root->left)
                return root->right;
            if(!root->right)
                return root->left;
            
            TreeNode* Min = findMinInRightSubtree(root->right);
            root->val = Min->val;
            root->right = deleteNode(root->right,Min->val);
        }
        return root;
    }
};