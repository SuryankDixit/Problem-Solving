#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/


void topView(Node * root) {
      if(root==nullptr)
        return;
    
    unordered_map<int,int> m;
    int mn,mx;
    mn=0;mx=0;
    queue<pair<struct Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp;
        temp = q.front();
        q.pop();
        int d= temp.second;
        root = temp.first;
        if(m.find(d)==m.end())
            m[d]=root->data;
        
        if(root->left!=nullptr){
            mn = min(mn,d-1);
            q.push(make_pair(root->left,d-1));
        }
        if(root->right!=nullptr){
            mx= max(mx,d+1);
            q.push(make_pair(root->right,d+1));
        }
        
    }
    for(int i=mn;i<=mx;i++){
        cout<<m[i]<<" ";
    }
}

}; //End of Solution