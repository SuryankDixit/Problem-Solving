// 101. Symmetric Tree Leetcode iterative

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
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push(make_pair(root->left,root->right));
        pair<TreeNode*,TreeNode*>p;
        while(!q.empty())
        {
            p=q.front();
            q.pop();
            if(p.first==NULL && p.second==NULL)
                continue;
            if(!p.first || !p.second)
                return false;
            if(p.first->val != p.second->val)
                return false;
            q.push(make_pair(p.first->left,p.second->right));
            q.push(make_pair(p.first->right,p.second->left));
        }
        return q.empty();
    }
};
