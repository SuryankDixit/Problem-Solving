
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
struct TreeNode {
    int val = 0;
    TreeNode* left;
    TreeNode* right;
 
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
 
void printTree(TreeNode* root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}
 
void dfsit(TreeNode* rt, int key,map<int, vector<TreeNode*> >& mp)
{
    if (!rt) {
        return;
    }
    mp[key].push_back(rt);
    dfsit(rt->right, key + 1, mp);
    dfsit(rt->left, key + 1, mp);
    rt->left = NULL;
    rt->right = NULL;
}
 
TreeNode* shiftRight(TreeNode* root)
{
    TreeNode* tmp = root;
    map<int, vector<TreeNode*> > mp;
    int i = 0;
    
    dfsit(root, 0, mp);
    int n = mp.size();
    
    queue<TreeNode*> q;
    TreeNode* node = new TreeNode(-1);
    q.push(node);
    while(i<n){
        auto v = mp[i];
        int j=0;
        while(j<v.size()){
            auto parent = q.front();
            q.pop();
            parent->right = v[j];
            q.push(v[j]);
            j++;
            if(j<v.size()){
                parent->left = v[j];
                q.push(v[j]);
                j++;
            }
        }
        i++;
    }
    return node->right;
}
 
int main()
{
 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root = shiftRight(root);

    printTree(root);
    return 0;
}