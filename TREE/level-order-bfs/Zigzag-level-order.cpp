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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode *> s1,s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int> v1;
            vector<int> v2;
            while(s2.size()>0){
                TreeNode* temp=s2.top();
                s2.pop();
                v1.push_back(temp->val);
                if(temp->right!=nullptr)
                   s1.push(temp->right);
                if(temp->left!=nullptr)
                    s1.push(temp->left);
            }
            if(v1.size()>0)
                ans.push_back(v1);
            while(s1.size()>0){
                TreeNode* temp = s1.top();
                s1.pop();
                v2.push_back(temp->val);
                if(temp->left!=nullptr)
                    s2.push(temp->left);
                if(temp->right!=nullptr)
                    s2.push(temp->right);
            }
            if(v2.size()>0)
                ans.push_back(v2);
        }
        return ans;
    }
};