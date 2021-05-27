#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode
{
    int val;
     
    vector<TreeNode*> children;
     
    TreeNode(int v)
    {
        val = v;
    }
};

double ans = 0.0;

vector<int> MaxAverage(TreeNode* root)
{
    if(!root){
        return {};
    }
    if(root->children.size()==0){
        ans = max(ans,(double)root->val);
        return {root->val,1};
    }

    int sum=0;
    int cnt=0;

    for(auto x: root->children){
        auto v = MaxAverage(x);
        sum += v[0];
        cnt += v[1];
    }
    cnt++;
    sum+=root->val;
    double avg = (double)sum/cnt;
    ans = max(ans,avg);
    return {sum,cnt};
}
 
// Driver Code
int main()
{
     
    // Given tree
    TreeNode *root = new TreeNode(20);
    TreeNode *left = new TreeNode(12);
    TreeNode *right = new TreeNode(18);
     
    root->children.push_back(left);
    root->children.push_back(right);
     
    left->children.push_back(new TreeNode(11));
    left->children.push_back(new TreeNode(3));
    right->children.push_back(new TreeNode(15));
    right->children.push_back(new TreeNode(8));
 
    // Function call
    MaxAverage(root);
 
    // Print answer
    printf("%0.1f\n", ans);
}