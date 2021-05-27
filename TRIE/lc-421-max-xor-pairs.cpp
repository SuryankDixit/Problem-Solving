#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        node* left;     // 0
        node* right;    // 1
        node(){
            left=nullptr;
            right=nullptr;
        }
};

class Trie{
    node* root;
    public:
        Trie(){
            root = new node();
        }
    
        void insert(int n){
            node *temp = root;
            for(int i=31;i>=0;i--){
                int bit = (n>>i)&1;
                if(bit==0){
                    if(!temp->left){
                        temp->left = new node;
                    }
                    temp=temp->left;
                }else{
                    if(!temp->right){
                        temp->right = new node();
                    }
                    temp=temp->right;
                }
            }
        }
        
        int max_XOR_helper(int n){
            int ans = 0;
            node* temp = root;
            for(int i=31;i>=0;i--){
                int bit = (n>>i)&1;
                if(bit==0){
                    if(temp->right){
                        temp=temp->right;
                        ans+= (1<<i);
                    }else{
                        temp=temp->left;
                    }
                }else{
                    if(temp->left){
                        temp=temp->left;
                        ans+= (1<<i);
                    }else{
                        temp=temp->right;
                    }
                }
            }
            return ans;
        }
};


class Solution {
public:
    
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans=0;
        for(auto x:nums){
            t.insert(x);
            ans = max(ans,t.max_XOR_helper(x));
        }
        return ans;
    }
};