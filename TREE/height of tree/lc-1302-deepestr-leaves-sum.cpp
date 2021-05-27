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
    unordered_map<int,vector<int>> m;
    int mx=INT_MIN;
    
    void dfs(TreeNode* root , int ht){
        if(!root)
            return;
        
        if(!root->left&&!root->right){
            mx=max(mx,ht);
            m[ht].push_back(root->val);
            return;
        }
        
        dfs(root->left,ht+1);
        dfs(root->right, ht+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root,0);
        int sum=0;
        for(auto x:m[mx])
            sum+=x;
        return sum;
    }
};