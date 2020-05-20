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
        if(root==nullptr)
            return 0;
        int Max=INT_MIN;
        int sum=0;
        int level=0;
        int ans_level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            sum=0;
            while(count>0)
            {
                TreeNode* temp;
                temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=nullptr)
                    q.push(temp->left);
                if(temp->right!=nullptr)
                    q.push(temp->right);
                count--;
            }
            level++;
            if(sum>Max)
            {
                Max=sum;
                ans_level=level;
            }
        }
        return ans_level;
    }
};
