//129. Sum Root to Leaf Numbers SOLUTION 2
// This solution is faster than the solution 1;


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
    int ans;
    int sumNumbers(TreeNode* root) {
        ans=0;
        int curr_sum=0;
        sum_numbers(root,curr_sum);
        return ans;
    }
    void sum_numbers(TreeNode* root,int curr_sum)
    {
        if(!root)
            return;
        
        curr_sum=curr_sum*10+root->val;
        if(root->left==NULL && root->right==NULL)
            ans=ans+curr_sum;
        
        sum_numbers(root->left,curr_sum);
        sum_numbers(root->right,curr_sum);
    }
};
