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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* temp =root;
        
        while(temp!=nullptr || !s.empty()){
            while(temp!=nullptr){
                ans.push_back(temp->val);
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();

            temp=temp->right;
        }
        return ans;
    }
};
