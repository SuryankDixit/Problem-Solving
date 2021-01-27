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
    
    bool dfs(TreeNode* node1, TreeNode* node2){
        if(node1==nullptr || node2 ==nullptr)
            return node1==node2;
        if(node1->val != node2->val)
            return false;
        return dfs(node1->left , node2->left) && dfs(node1->right, node2->right);
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr)
            return p==q;
        if(p->val!=q->val)
            return false;
        return dfs(p->left,q->left) && dfs(p->right,q->right);
    }
};