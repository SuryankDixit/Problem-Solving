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
    string v;
    vector<string> ans;
    
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(!root->left&&!root->right){
            string x = to_string(root->val);
            v+=x;
            ans.push_back(v);
            int k=x.size();
            while(k--)
                v.pop_back();
        }
        string x = to_string(root->val);
        v+=x;
        v+="->";
        dfs(root->left);
        dfs(root->right);
        int k = x.size()+2;
        while(k--){
            v.pop_back();
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        dfs(root);
        return ans;
    }
};