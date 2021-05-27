// O(n) time complexity and O(n) space complexity.

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
    
    unordered_map<TreeNode*,int> m;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
      
        unordered_map<TreeNode* ,TreeNode*> parent;
        parent[root] = NULL;
        TreeNode* prev = NULL;
        dfs(root,parent,root);
        
        unordered_map<TreeNode* ,int> seen;
        queue<TreeNode*> q;
        q.push(target);
        seen[target]++;
        int k=0;
        while(k!=K)
        {
            int count = q.size();
            while(count>0){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL && seen.find(temp->left) == seen.end()){
                    q.push(temp->left);
                    seen[temp->left]++;
                }
                if(temp->right!=NULL && seen.find(temp->right) == seen.end()){
                    q.push(temp->right);
                    seen[temp->right]++;
                }
                if(parent[temp] != temp && seen.find(parent[temp]) == seen.end()){
                    q.push(parent[temp]);
                    seen[parent[temp]]++;
                }
                count--;
            }
            k++;
        }
        vector<int> v;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
        }
        return v;
    }
    
    void dfs(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent, TreeNode* &prev)
    {
        if(root == NULL)
            return ;
        
        parent[root] = prev;
        dfs(root->left, parent , root);
        dfs(root->right, parent, root);
    }
};
