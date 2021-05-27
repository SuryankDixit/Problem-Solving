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
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        int max_ht=0;
        for(auto child: root->children){
            int ht = maxDepth(child);
            max_ht = max(ht,max_ht);
        }
        return max_ht+1;
    }
};