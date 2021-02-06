/* Set next of p and all descendents of p by traversing them in reverse Inorder */

/*
Node Structure

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    next = NULL;
	}
};
*/

void dfs(struct node* root,struct node* &prev){
    if(root==nullptr)
        return;
    
    dfs(root->left,prev);
    if(prev!=nullptr){
        prev->next = root;
    }
    prev=root;
    dfs(root->right,prev);
}

void populateNext(struct node* root)
{
    if(root==nullptr)
        return;
    struct node* prev=nullptr;
    dfs(root,prev);
    return;
}