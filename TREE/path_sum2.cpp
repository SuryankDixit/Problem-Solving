113. Path Sum II Leetcode2

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> paths;
        findpaths(root,sum,path,paths);
        return paths;
    }
    void findpaths(TreeNode* root,int sum,vector<int> &path,vector<vector<int>> &paths)
    {
        if(root==NULL)
            return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==root->val)
            paths.push_back(path);
        findpaths(root->left,sum-root->val,path,paths);
        findpaths(root->right,sum-root->val,path,paths);
        path.pop_back();
    }
};
