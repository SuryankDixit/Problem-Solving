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
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
       if( r1 == nullptr && r2 == nullptr )
            return true;
        
        if( r1 == nullptr || r2 == nullptr )
            return false;
        
        if( r1->val != r2->val )
            return false;
        
        bool ll =  flipEquiv( r1->left, r2->left );
        bool rr=false;
        if(ll){
            rr =  flipEquiv( r1->right, r2->right );   
        }
        
        if( rr && ll )
            return true;
        
        bool lr =  flipEquiv( r1->left, r2->right );
        bool rl = false;
        if(lr){
             rl =  flipEquiv( r1->right, r2->left );   
        }
        
        if( rl && lr )
            return true;
        
        return false;
    }
};