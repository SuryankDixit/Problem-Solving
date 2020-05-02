//108. Convert Sorted Array to Binary Search Tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          return toBST(nums,0,nums.size());
    }
    
    TreeNode* toBST(vector<int> &nums,int l,int r)
    {
        int mid=(l+r)/2;
        if(r<=l)
            return NULL;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=toBST(nums,l,mid);
        root->right=toBST(nums,mid+1,r);
        return root;
    }
};
