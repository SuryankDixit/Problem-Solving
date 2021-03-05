#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dfs(vector<vector<int>>& v,int i,int j,int color,int pre,vector<vector<int>> &visited){
        
        if(i<0 || i>=v.size() || j<0 || j>=v[0].size()){
            return color;
        }
        
        if(visited[i][j]==1)
            return -1;
        
        if(v[i][j]!=pre)
            return color;
        
        visited[i][j]=1;
        int l=dfs(v,i,j-1,color,pre,visited);
        int r=dfs(v,i,j+1,color,pre,visited);
        int u=dfs(v,i-1,j,color,pre,visited);
        int d=dfs(v,i+1,j,color,pre,visited);
        if(l==color||r==color||u==color||d==color)
            v[i][j]=color;
        return -1;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& v, int r0, int c0, int color) {
        if(v.empty())
            return v;
        
        vector<vector<int>> visited(v.size(),vector<int>(v[0].size(),0));
        dfs(v,r0,c0,color,v[r0][c0],visited);
        return v;
    }
};