#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 100005;

class Solution {
public:
    vector<int> visited;
    
    bool dfs(int s,int color,vector<vector<int>>& graph){
        visited[s]=color;
        for(auto x:graph[s]){
            if(visited[x]==0){
                bool f = dfs(x,3-color,graph);
                if(f == false)
                    return false;
            }else if(visited[x]==visited[s]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        visited.resize(101,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                bool status = dfs(i,1,graph);
                if(!status)
                    return false;
            }
        }
        return true;
    }
};