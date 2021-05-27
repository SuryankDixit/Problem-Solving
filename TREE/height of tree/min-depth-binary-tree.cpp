#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        if(root->left==NULL && root->right!=NULL)
            return minDepth(root->right)+1;
        if(root->right==NULL && root->left!=NULL)
            return minDepth(root->left)+1;
        return min((minDepth(root->left)+1) , (minDepth(root->right)+1));
    }
};