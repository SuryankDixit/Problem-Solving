bool hasPathSum(Node *root, int s) {
    // Your code here
    if(root==nullptr){
        return (s==0);
    }
    
    int x = s-root->data;
    if(root->left==nullptr && root->right==nullptr){
        if(x==0)
            return true;
        return false;
    }
    bool l = hasPathSum(root->left,x);
    bool r = hasPathSum(root->right,x);
    if(l||r)
        return true;
    return false;
}