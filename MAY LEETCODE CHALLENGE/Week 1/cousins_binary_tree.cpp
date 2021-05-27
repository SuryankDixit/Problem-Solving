
/*
Cousins in Binary Tree
Solution
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
*/

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
    bool isCousins(TreeNode* root, int x, int y) {
        
        int flag=0;
        vector<int> v(2,0);  // stores the parent of x and y .
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int count=q.size();
            while(count>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                    if(temp->left->val==x)
                    {
                        v[0]=temp->val;
                        flag++;
                    }
                    else if(temp->left->val==y)
                    {
                        v[1]=temp->val;
                        flag++;
                    }
                }
                
                if(temp->right!=NULL){
                    q.push(temp->right);
                    if(temp->right->val==x)
                    {
                        v[0]=temp->val;
                        flag++;
                    }
                    else if(temp->right->val==y)
                    {
                        v[1]=temp->val;
                        flag++;
                    }
                }
                count--;
            }
            if(flag==0 && v[0]==v[1])
                    continue;
                else if(flag==2 && v[0]!=v[1])
                    return true;
                else
                    return false;
        }
        return false;
    }
};