/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* root,int target,vector<vector<int>> &ans,vector<int> &v){
    if(root==nullptr){
        v.push_back(-1);
        return;
    }
    target-=root->val;
    v.push_back(root->val);
    if(!root->left && ! root->right && target==0){
        ans.push_back(v);
    }
    dfs(root->left,target,ans,v);
    v.pop_back();
    dfs(root->right,target,ans,v);
    v.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    vector<int> v;
    dfs(A,B,ans,v);
    return ans;
}
