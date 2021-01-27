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
    vector<double> averageOfLevels(TreeNode* root) {
        // vector<vector<int>> ans;
        if(root ==NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<double> ans;
        while(!q.empty()){
            int k = q.size();
            double sum=0;
            double x=k;
            while(k--){
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            ans.push_back(sum/x);
        }
        return ans;
    }
};