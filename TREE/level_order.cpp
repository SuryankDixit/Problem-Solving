//102. Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL)
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int count=q.size();
            vector<int> v1;
            while(count>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                v1.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                count--;
            }
            v.push_back(v1);
        }
        return v;
    }
};
