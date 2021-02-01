/* C++ program for special order traversal */
#include <iostream> 
#include <queue> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct Node 
{ 
    int data; 
    Node *left; 
    Node *right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
Node *newNode(int data) 
{ 
    Node *node = new Node; 
    node->data = data; 
    node->right = node->left = NULL; 
    return node; 
} 
  
/* Given a perfect binary tree, print its nodes in specific 
   level order */
void printSpecificLevelOrder(Node *root) 
{ 
    if (root == NULL) 
        return; 
   
    cout << root->data<<" "; 
  
   
    queue <Node *> q; 
    q.push(root->left); 
    q.push(root->right); 

    
    while (!q.empty()) { 
        int k = q.size();
        while(k){
            Node* temp1;
            Node* temp2;
            temp1 = q.front(); q.pop();
            temp2 = q.front(); q.pop();
            cout<<temp1->data<<" "<<temp2->data<<" ";
            if(temp1->left!=nullptr && temp2->right!=nullptr){
                q.push(temp1->left);
                q.push(temp2->right);
            }
            if(temp2->left!=nullptr && temp1->right!=nullptr){
                q.push(temp1->right);
                q.push(temp2->left);
            }
            k=k-2;
        }
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    //Perfect Binary Tree of Height 4 
    Node *root = newNode(1); 
  
    root->left        = newNode(2); 
    root->right       = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31); 
  
    cout << "Specific Level Order traversal of binary tree is \n"; 
    printSpecificLevelOrder(root); 
  
    return 0; 
}