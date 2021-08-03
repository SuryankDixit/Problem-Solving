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
    int ans =0;
    unordered_map<int,int> m;
    
    void dfs(TreeNode* root, int t,int sum){
        if(!root)
            return;
        sum+=root->val;
        if(m.find(sum-t)!=m.end())
            ans+= m[sum-t];
        m[sum]++;
        dfs(root->left,t,sum);
        dfs(root->right,t,sum);
        m[sum]--;
        return;
    }
    
    int pathSum(TreeNode* root, int t) {
        if(!root)
            return 0;
        m[0]=1;
        int sum=0;
        dfs(root,t,sum);
        return ans;
    }
};