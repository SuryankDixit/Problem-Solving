Time => O(n^2)
Space => O(n)
approach => find distance of each node from root and then find find LCA of each node with target node. Then use distance formula.

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
    
    unordered_map<TreeNode*,int> m;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        int d=0;
        distance(root,d);
        vector<int> v;
        
        for(auto i=m.begin(); i!=m.end(); i++)
        {
            TreeNode* Lca = lca(root,target,i->first);
            int dis = m[target] + m[i->first] - 2*m[Lca];
            if(dis==K)
                v.push_back((i->first)->val);
        }
        
        return v;
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return root;
        
        if(root == p || root ==q)
            return root;
        
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        return root;
    }
    
    void distance(TreeNode* root,int d)
    {
        if(root==NULL)
            return;
        
        distance(root->left,d+1);
        distance(root->right,d+1);
        m[root]=d;
        d--;
  }      
};
