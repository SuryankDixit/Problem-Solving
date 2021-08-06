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
    vector<int> v;
    int findNodeInSubtree(TreeNode* root){
        if(!root)
            return 0;
        int l = findNodeInSubtree(root->left);
        int r = findNodeInSubtree(root->right);
        v[0]=l;v[1]=r;
        return l+r+1;
    }
    
    int dfs(TreeNode* root, int x){
        if(!root)
            return 0;
        if(root->val==x)
            return findNodeInSubtree(root);
        return max(dfs(root->left,x),dfs(root->right,x));
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(!root)
            true;
        v.resize(2,0);
        if(root->val==x){
            int cnt1=findNodeInSubtree(root->left);
            int cnt2=findNodeInSubtree(root->right);
            return cnt1!=cnt2;
        }
        int p1 = dfs(root,x);
        int p2 = n-p1;
        if(p1<=p2)
            return true;
        else{
            int p2_dash = max(v[0],v[1]);
            int p1_dash = n-p2_dash;
            if(p1_dash<p2_dash)
                return true;
        }
        return false;
    }
};