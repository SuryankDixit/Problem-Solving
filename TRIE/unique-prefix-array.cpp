/*
Find shortest unique prefix for every word in a given list
Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove = dov 
             duck = du
             z   => zebra 

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: {geeksf, geeksg, geeksq}
*/

/*
    Cretae Trie: O(N*k)
    Insert: O(k)
    Search: O(k)
    LookUp for all Words: O(N*k)
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char,Node*> children;
        bool terminal;
        int cnt;

        Node(char c){
            data = c;
            terminal = false;
            cnt=1;
        }
};

class Trie{
    Node* root;
    public:
        Trie(){
            root = new Node('\0');
        }

        void insert(string w){
            Node* temp = root;
            for(int i=0;i<w.size();i++){
                char ch = w[i];
                if(temp->children.count(ch)){
                    temp = temp->children[ch];
                    temp->cnt++;
                }else{
                    Node* n = new Node(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
            }
            temp->terminal = true;
        }

        string find(string w){
            // cout<<w<<" ";
            Node* temp = root;
            string ans="";
            for(int i=0;i<w.size();i++){
                char ch = w[i];
                temp = temp->children[ch];
                ans.push_back(ch);
                if(temp->cnt==1){
                    // cout<<endl;
                    return ans;
                }
            }
            return "-";
        }
};

int main(){
    Trie t;
    // vector<string> v{"dogs","zebra","cobra","cobras","dog", "duck", "dove"};
    vector<string> v{"zebra", "dog", "dogg", "duck", "dove"};
    vector<string> ans;
    for(int i=0;i<v.size();i++){
        t.insert(v[i]);
    }

    for(int i=0;i<v.size();i++){
        string s = t.find(v[i]);
        ans.push_back(s);
    }

    for(auto x:ans){
        cout<<x<<" ";
    }
}
