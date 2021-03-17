#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    
    bool dfs(vector<vector<int>>& graph, int i, vector<int> &v){
        v[i]=1;
        for(auto x:graph[i]){
            if(v[x]==1)
                return false;
            if(v[x]==0){
                bool s = dfs(graph,x,v);
                if(s==false)
                    return false;
            }
        }
        v[i]=2;
        ans.push_back(i);
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            if(v[i]==0){
                dfs(graph,i,v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};