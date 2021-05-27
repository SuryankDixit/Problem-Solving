// A wrapper over leftViewUtil()
vector<int> leftView(Node *root)
{
    if(root==nullptr)
        return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int k =q.size();
        int x= k;
        while(k){
            // cout<<k<<" "<<q.size()<<endl;
            Node* temp =q.front();
            q.pop();
            if(k==x){
                ans.push_back(temp->data);
            }
            if(temp->left!=nullptr)
                q.push(temp->left);
            if(temp->right!=nullptr)
                q.push(temp->right);
            k--;
        }
    }
    return ans;
}
