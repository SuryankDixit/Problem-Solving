Time => O(n)
Space => O(n)

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   vector<TreeNode* > v1,v2;
        int flag=0;
        path(root,p,v1,flag);
        flag=0;
        path(root,q,v2,flag);
        
        
        int len = min(v1.size(),v2.size());
        TreeNode *ans;
        for(int i=0;i<len;i++){
            if(v1[i] == v2[i]){
                ans = v1[i];
                continue;
            }
            else{
                break;
            }
                
        }
        return ans;
        
    }
    
    void path(TreeNode *root,TreeNode *x,vector<TreeNode* > &v,int &flag)
    {
        if(root==NULL)
            return;
        if(root == x){
            v.push_back(x);
            flag=1;
            return;
        }
        
        if(flag==0)
            v.push_back(root);
        path(root->left,x,v,flag);
        path(root->right,x,v,flag);
        if(flag==0)
            v.pop_back();
    }

};
