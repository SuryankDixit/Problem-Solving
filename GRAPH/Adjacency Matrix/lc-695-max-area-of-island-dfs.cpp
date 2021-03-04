#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans=0;
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    
    void dfs(int i,int j,vector<vector<int>> &v,int &cnt){
        if(i<0||j<0||i>=v.size()||j>=v[0].size()){
            return;
        }
        
        if(v[i][j]!=1){
            return;
        }
        
        v[i][j]= 0;
        ans=max(ans,cnt);
        cnt++;
        for(int x=0;x<4;x++){
            dfs(i+dx[x],j+dy[x],v,cnt);
        }
        return; 
    }
    
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int n=v.size();
        int n1=v[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n1;j++){
                if(v[i][j]==1){
                    int cnt=1;
                    dfs(i,j,v,cnt);
                }
            }
        }
        return ans;
    }
};