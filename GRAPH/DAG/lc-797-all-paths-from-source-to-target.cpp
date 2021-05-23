#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void dfs(vector<vector<int>> &g,int v,vector<int>&p){
        p.push_back(v);
        if(v==n){
            ans.push_back(p);
            p.pop_back();
            return;
        }
        for(auto x:g[v]){
            dfs(g,x,p);
        }
        p.pop_back();
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        n = g.size()-1;
        vector<int> v;
        dfs(g,0,v);
        return ans;
    }
};