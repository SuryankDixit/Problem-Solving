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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ans = INT_MIN;
        int l=0;
        int level=0;
        while(!q.empty()){
            l++;
            int k = q.size();
            int sum=0;
            while(k--){
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            if(sum>ans){
                level=l;
                ans=sum;
            }
        }
        return level;
    }
};