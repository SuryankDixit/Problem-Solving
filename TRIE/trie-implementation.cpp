#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        char data;
        unordered_map<char,Node*> children;
        bool terminal;
    
        Node(char c){
            data =c;
            terminal = false;
        }
};

class Trie{
    Node* root;
    int cnt;    // how many words we have inserted in the trie;
    public:
        Trie(){
            root = new Node('\0');
            cnt=0;
        }

        void insert(string w){
            Node *temp = root;
            for(int i=0;i<w.size();i++){
                char ch = w[i];
                if(temp->children.count(ch)){       // return 0 or 1 
                    temp = temp->children[ch];
                }else{
                    Node* n = new Node(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
            }
            temp->terminal = true;
        }

        bool find(string w){
            Node* temp = root;
            for(int i=0;i<w.size();i++){
                char ch = w[i];
                if(temp->children.count(ch)==0){
                    return false;
                }
                temp=temp->children[ch];
            }
            return temp->terminal;
        }
};

int main(){
    Trie t;
    vector<string> v{"a","hello","no","not","none","hi"};
    for(int i=0;i<v.size();i++){
        t.insert(v[i]);
    }
    string w;
    cin>>w;
    if(t.find(w)){
        cout<<"Present\n";
    }else{
        cout<<"Not Present\n";
    }
}