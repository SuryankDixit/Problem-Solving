#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char,Node*> children;
        bool terminal;
        int cnt_str;    // tells that how many strings are passing through this node,
    Node(char ch){
        data = ch;
        cnt_str=1;
    }
};


class Trie{
    Node *root;
    public:
        Trie(){
            root = new Node('-');
        }

        void insert(string str){
            Node* temp= root;
            for(auto ch: str){
                // if (temp->children.find(ch) == temp->children.end())
                if (temp->children.count(ch)){
                    temp=temp->children[ch];
                    temp->cnt_str++;
                }else{
                    temp->children[ch] = new Node(ch);
                    temp=temp->children[ch];
                }
            }
            temp->terminal = true;
        }

        string find(string str){
            Node* temp = root;
            string prefix="";
            for(auto ch:str){
                temp = temp->children[ch];
                prefix+=temp->data;
                if(temp->cnt_str==1){
                    return prefix;
                }
            }
            return "-";
        }
};


vector<string> shortestCommonPrefix(vector<string> &v){
    Trie t;
    for(auto s:v){
        t.insert(s);
    }
    vector<string> ans;
    for(auto s:v){
        ans.push_back(t.find(s));
    }
    return ans;
}

int main(){
    vector<string> v{"zebra","dog","dogg","duck","dove"};
    vector<string> res = shortestCommonPrefix(v);
    for(auto x:res)
        cout<<x<<" ";
}