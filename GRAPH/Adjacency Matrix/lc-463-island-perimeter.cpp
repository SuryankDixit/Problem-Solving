#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& v,int &ans){
        if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]==0){
            ans++;
            return ;
        }
        
        if(v[i][j]==-1)
            return;
        
        v[i][j]=-1;
        dfs(i-1,j,v,ans);
        dfs(i,j-1,v,ans);
        dfs(i,j+1,v,ans);
        dfs(i+1,j,v,ans);
        return;
    }
    
    int islandPerimeter(vector<vector<int>>& v) {
        if(v.empty())
            return 0;
        
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){
                    dfs(i,j,v,ans);
                    return ans;
                }
            }
        }
        return ans;
    }
};