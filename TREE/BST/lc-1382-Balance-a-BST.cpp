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
    vector<TreeNode*> v;
    
    void storeIn(TreeNode* root){
        if(!root)return;
        storeIn(root->left);
        v.push_back(root);
        storeIn(root->right);
        root->left=root->right=nullptr;
    }
    
    TreeNode* buildBst(int i,int j){
        // cout<<i<<" "<<j<<endl;
        if(i>j)
            return nullptr;
        if(i==j)
            return v[i];
        int mid=(i+j)/2;
        TreeNode* root = v[mid];
        root->left = buildBst(i,mid-1);
        root->right = buildBst(mid+1,j);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)return root;
        storeIn(root);
        return buildBst(0,v.size()-1);
    }
};