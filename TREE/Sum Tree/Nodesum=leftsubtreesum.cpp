// C++ program to store sum of nodes 
// in left subtree in every node  
#include<bits/stdc++.h>  
  
using namespace std;  
  
// A tree node  
class node  
{  
    public: 
    int data;  
    node* left, *right;  
      
    /* Constructor that allocates a new node with the  
    given data and NULL left and right pointers. */
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
};  
  
// Function to modify a Binary Tree 
// so that every node stores sum of  
// values in its left child including  
// its own value  
int updatetree(node *root)  
{  
    // Base cases  
    if (!root)  
        return 0;  
    if (root->left == NULL && root->right == NULL)  
        return root->data;  
  
    // Update left and right subtrees  
    int leftsum = updatetree(root->left);  
    int rightsum = updatetree(root->right);  
  
    // Add leftsum to current node  
    root->data += leftsum;  
  
    // Return sum of values under root  
    return root->data + rightsum;  
}  
  
// Utility function to do inorder traversal  
void inorder(node* node)  
{  
    if (node == NULL)  
        return;  
    inorder(node->left);  
    cout<<node->data<<" ";  
    inorder(node->right);  
}  
  
// Driver code  
int main()  
{  
    /* Let us construct below tree  
                1  
            / \  
            2 3  
            / \ \  
            4 5 6 */
    struct node *root = new node(1);  
    root->left     = new node(2);  
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);  
    root->right->right = new node(6);  
  
    updatetree(root);  
  
    cout << "Inorder traversal of the modified tree is: \n";  
    inorder(root);  
    return 0;  
}  