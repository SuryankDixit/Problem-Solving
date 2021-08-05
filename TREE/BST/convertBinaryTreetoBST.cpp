class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void storeInorder(Node* root,vector<int>&v){
        if(!root)return;
        storeInorder(root->left,v);
        v.push_back(root->data);
        storeInorder(root->right,v);
    }
    
    Node* tree(Node* root,vector<int>&v,int &i){
        if(!root)return root;
        tree(root->left,v,i);
        root->data=v[i++];
        tree(root->right,v,i);
        return root;
    }
    
};