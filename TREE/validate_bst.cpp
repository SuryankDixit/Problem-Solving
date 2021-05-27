// 98. Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        validBST(root,v);
        bool status=true;
        if(v.size()==0)
            return true;
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1])
                status=false;
        }
        return status;
    }
    void validBST(TreeNode* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        
        validBST(root->left,v);
        v.push_back(root->val);
        validBST(root->right,v);
    }
};
