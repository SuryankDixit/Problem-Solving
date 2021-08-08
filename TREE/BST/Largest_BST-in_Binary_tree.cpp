struct Data{
    bool isBst;
    int size;
    int min;
    int max;
};

void print(Data d){
    cout<<d.size<<" "<<d.min<<" "<<d.max<<endl;
}

Data dfs(Node* root){
    // cout<<"hi";
     if(!root){
         Data d;
         d.isBst=true;
         d.size=0;
         d.min=INT_MAX;
         d.max=INT_MIN;
         return d;
     }
     
     Data l = dfs(root->left);
     Data r = dfs(root->right);
     
     Data ans;
     
     if(!l.isBst || !r.isBst || (l.max >= root->data || r.min <= root->data)){
         ans.isBst = false;
         ans.size = max(l.size,r.size);
         return ans;
     }
     
     ans.isBst = true;
     ans.size = l.size+r.size+1;
     ans.min = (root->left) ? l.min : root->data;
     ans.max = (root->right) ? r.max : root->data;
    //  print(ans);
     
     return ans;
}

int largestBst(Node *root)
{
	if(!root)return 0;
	Data d = dfs(root);
	return d.size;
}