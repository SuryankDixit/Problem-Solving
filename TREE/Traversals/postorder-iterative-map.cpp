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
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        unordered_map<TreeNode*, int> state;
        stack<TreeNode*> st;
        vector<int> ans;
        
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            if(temp==nullptr){
                st.pop();
                continue;
            }
            if(state[temp]==0){
                st.push(temp->left);
            }else if(state[temp]==1){
                st.push(temp->right);
            }else if(state[temp]==2){
                ans.push_back(temp->val);
            }else{
                st.pop();
            }
            state[temp]++;
        }
        return ans;
    }
};