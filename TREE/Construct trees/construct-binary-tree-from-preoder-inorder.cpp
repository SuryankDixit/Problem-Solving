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
    // [1,2]
    // [2,1]
    unordered_map<int,int> m;
    
    int idx1 = 0;
    TreeNode* solve(vector<int>& pre,int i, int j){

        if(i>j)
            return nullptr;
        
        cout<<i<<" "<<j<<endl;
        int x = pre[idx1];
        int idx2 = m[x];
        
        TreeNode* root = new TreeNode(pre[idx1++]);
        
        if(i==j){
            return root;
        }
        root->left = solve(pre,i,idx2-1);
        root->right = solve(pre,idx2+1,j);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n =in.size();
        if(n==0){
            return nullptr;
        }
        for(int i=0;i<n;i++){
            m[in[i]] = i;
        }
        return solve(pre,0,n-1);
    }
};