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
    unordered_map<int,vector<pair<int,int>>> m;
    int Min=INT_MAX;
    int Max=INT_MIN;
    
    void solve(TreeNode* root, int x,int y){
        if(!root)
            return;
        m[x].push_back({x+y,root->val});
        Min= min(Min,x);
        Max= max(Max,x);
        solve(root->left,x-1,y+1);
        solve(root->right,x+1,y+1);
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        solve(root,0,0);
        vector<vector<int>> ans;
        for(int i=Min;i<=Max;i++){
            auto x = m[i];
            sort(x.begin(),x.end());
            vector<int> v;
            for(auto c:x){
                v.push_back(c.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};