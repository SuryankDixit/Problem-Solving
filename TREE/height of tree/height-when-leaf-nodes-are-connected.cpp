
/*Structure of the node of the binary tree

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

bool isLeaf(Node* node){
    
    return (node->left && node->left->right == node) 
                        && 
           (node->right && node->right->left == node) ;
}

// Return the height of the given special binary tree
int findTreeHeight(Node* root)
{
	if(root==nullptr){
	    return 0;
	}
	
	if(isLeaf(root)){
	    return 1;
	}
	
	return max(findTreeHeight(root->left),findTreeHeight(root->right))+1;
}