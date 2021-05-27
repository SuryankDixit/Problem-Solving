//103. Binary Tree Zigzag Level Order Traversal

// THIS CODE CAN BE WRITTEN IN A MORE BETTER WAY.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL)
            return v;
        
        stack<TreeNode*> s1,s2;
        bool r_side=true;
        s1.push(root);
        vector<int> v2;
        v2.push_back(root->val);
        v.push_back(v2);
        
        while(!s1.empty() || !s2.empty())
        {
            vector<int> v1;
            int count1=s1.size();
            int count2=s2.size();
            while(count1>0 && r_side==true)
            {
                TreeNode* temp=s1.top();
                s1.pop();
               
                if(temp->right!=NULL){
                    s2.push(temp->right);
                    v1.push_back(temp->right->val);
                }
                if(temp->left!=NULL){
                    s2.push(temp->left);
                    v1.push_back(temp->left->val);
                }
                
                count1--;
            }
            
            while(count2>0 && r_side==false)
            {
                TreeNode* temp=s2.top();
                s2.pop();
                if(temp->left!=NULL){
                    s1.push(temp->left);
                    v1.push_back(temp->left->val);
                }
                if(temp->right!=NULL){
                    s1.push(temp->right);
                    v1.push_back(temp->right->val);
                }
                
                count2--;
            }
            
            if(r_side==true)
                r_side=false;
            else
                r_side=true;
            if(v1.size()>0)
            v.push_back(v1);
            
        }
        
        return v;
    }
};
