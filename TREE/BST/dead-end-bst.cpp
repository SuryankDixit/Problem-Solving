/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

bool dfs(Node* root, int l,int r){
    
    if(!root)return false;
    if((root->data==l+1 && root->data==r-1))return true;
    
    
    return dfs(root->left,l,root->data) || dfs(root->right,root->data,r);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    if(!root)return false;
    return dfs(root,0,INT_MAX);
}