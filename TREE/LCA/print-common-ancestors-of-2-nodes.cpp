#include <bits/stdc++.h> 
using namespace std; 
  
// A Binary Tree Node 
struct Node { 
    struct Node* left, *right; 
    int key; 
}; 
  
// Utility function to create a new tree Node 
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Utility function to find the LCA of two given values 
// n1 and n2. 
struct Node* findLCA(struct Node* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) 
        return NULL; 
  
    // If either n1 or n2 matches with root's key, 
    // report the presence by returning root (Note 
    // that if a key is ancestor of other, then the 
    // ancestor key becomes LCA 
    if (root->key == n1 || root->key == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    Node* left_lca = findLCA(root->left, n1, n2); 
    Node* right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then 
    // one key  is present in once subtree and other is 
    // present in other, So this node is the LCA 
    if (left_lca && right_lca) 
        return root; 
  
    // Otherwise check if left subtree or right 
    // subtree is LCA 
    return (left_lca != NULL) ? left_lca : right_lca; 
} 
  
// Utility Function to print all ancestors of LCA 
bool printAncestors(struct Node* root, int target) 
{ 
    /* base cases */
    if (root == NULL) 
        return false; 
  
    if (root->key == target) { 
        cout << root->key << " "; 
        return true; 
    } 
  
    /* If target is present in either left or right 
      subtree of this node, then print this node */
    if (printAncestors(root->left, target) || 
        printAncestors(root->right, target)) { 
        cout << root->key << " "; 
        return true; 
    } 
  
    /* Else return false */
    return false; 
} 
  
// Function to find nodes common to given two nodes 
bool findCommonNodes(struct Node* root, int first, 
                                       int second) 
{ 
    struct Node* LCA = findLCA(root, first, second); 
    if (LCA == NULL) 
        return false; 
  
    printAncestors(root, LCA->key); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree given in the above 
    // example 
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->right->left->left = newNode(9); 
    root->right->left->right = newNode(10); 
  
    if (findCommonNodes(root, 9, 7) == false) 
        cout << "No Common nodes"; 
  
    return 0; 
} 