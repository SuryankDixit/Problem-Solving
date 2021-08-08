class Solution
{
    public:
    int ans;
void solve(Node* root, int k, int &idx){
    if(!root)return;
    solve(root->right,k,idx);
    if(k==idx){
        ans=root->data;
        idx++;
        return;
    }else{
        idx++;
    }
    solve(root->left,k,idx);
}
    int kthLargest(Node *root, int K)
    {
        ans=-1;
        int cnt=1;
        solve(root,K,cnt);
        return ans;
    }
};