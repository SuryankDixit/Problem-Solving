// 129. Sum Root to Leaf Numbers SOLUTION 1
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
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> v1;
        vector<int> v;
        sum_numbers(root,v,v1);
        int sum=0;
        for(int i=0;i<v1.size();i++)
        {
            int num=0;
            for(int j=v1[i].size()-1;j>=0;j--)
            {
                num=num+(v1[i][j]*pow(10,v1[i].size()-1-j));
            }
            sum=sum+num;
            
        }
        return sum;
    }
    void sum_numbers(TreeNode* root,vector<int> &v,vector<vector<int>> &v1)
    {
        if(root==NULL)
            return;
        
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
            v1.push_back(v);
        sum_numbers(root->left,v,v1);
        sum_numbers(root->right,v,v1);
        v.pop_back();
    }
};
