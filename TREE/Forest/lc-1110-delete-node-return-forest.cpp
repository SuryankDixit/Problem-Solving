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
    unordered_set<int> m;
    vector<TreeNode*> ans;
    
    TreeNode* postorder(TreeNode* root){
        if(!root)
            return nullptr;
        
        root->left = postorder(root->left);
        root->right = postorder(root->right);
        int val = root->val;
        if(m.find(val)!=m.end()){
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            delete(root);
            return nullptr;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x:to_delete)
            m.insert(x);
        TreeNode* x = postorder(root);
        if(x)
            ans.push_back(x);
        return ans;
    }
};