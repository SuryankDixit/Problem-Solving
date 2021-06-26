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
    unordered_map<int,int> m;
    int Max=INT_MIN;
    
    void dfs(TreeNode* root, int y){
        if(!root)
            return;
        m[y] = root->val;
        Max = max(Max,y);
        dfs(root->left,y+1);
        dfs(root->right,y+1);
        return ;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        dfs(root,0);
        vector<int> ans;
        for(int i=0;i<=Max;i++)
            ans.push_back(m[i]);
        return ans;
    }
};


/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k =q.size();
            int x= k;
            while(k){
                // cout<<k<<" "<<q.size()<<endl;
                TreeNode* temp =q.front();
                q.pop();
                if(k==x){
                    ans.push_back(temp->val);
                }
                if(temp->right!=nullptr)
                    q.push(temp->right);
                if(temp->left!=nullptr)
                    q.push(temp->left);
                k--;
            }
        }
        return ans;
    }
};

*/


/*
class Solution {
public:
    int max_level=0;
    void dfs(TreeNode* root, vector<int> &ans,int level){
        if(root ==nullptr)
            return ;
        if(max_level<level){
            ans.push_back(root->val);
            max_level = level;
        }
        dfs(root->right,ans,level+1);
        dfs(root->left,ans,level+1);
        return ;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
            return {};
        vector<int> ans;
        dfs(root,ans,1);
        return ans;
    }
};
