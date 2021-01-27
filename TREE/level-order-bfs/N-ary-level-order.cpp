/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        queue<Node*> q;
        q.push(root);
        // ans.push_back({root->val});
        while(!q.empty()){
            vector<int> v;
            int k = q.size();
            while(k--){
                Node* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                for(auto child:temp->children)
                    q.push(child);
            }
            ans.push_back(v);
        }
        return ans;
    }
};