
bool dfs(Node* root,int x,vector<int>& ans){
    if(root == nullptr)
        return false;
    if(root->data == x)
        return true;
        
    bool l = dfs(root->left,x,ans);
    bool r = dfs(root->right,x,ans);
    if(l||r){
        ans.push_back(root->data);
        return true;
    }
    return false;
}


vector<int> Ancestors(struct Node *root, int target)
{
     vector<int> ans;
     if(root==nullptr)
        return ans;
    dfs(root,target,ans);
    // reverse(ans.begin(),ans.end());
    return ans;
}