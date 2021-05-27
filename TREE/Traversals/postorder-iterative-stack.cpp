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
    
    // unordered_map<TreeNode*, int> cnt;
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, int>> S;
    
    vector<int> ans;
    S.push({root, 0});
    while(!S.empty()){
        pair<TreeNode*, int> t = S.top();
        
        TreeNode* cur = t.first;
        int state = t.second;
        
        S.pop();

        if(cur == NULL or state == 3) continue;
        
        S.push({cur, state+1});
        
        if (state == 0) S.push({cur->left, 0});
        else if (state == 2) ans.push_back(cur->val);
        else if (state == 1) S.push({cur->right, 0});
    }
    return ans;
    }
};