#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    int n,m;
    vector<vector<int>> vis;
    
    bool isSafe(int x,int y){
        if(x>=0&&y>=0&&x<n&&y<m)
            return true;
        return false;
    }
    
    void dfs(int t,int i,int j,vector<vector<int>>& grid){
        if(!isSafe(i,j) || vis[i][j]==1)
            return;
        if(grid[i][j]>t)
            return;
        vis[i][j]=1;
        dfs(t,i-1,j,grid);
        dfs(t,i+1,j,grid);
        dfs(t,i,j-1,grid);
        dfs(t,i,j+1,grid);
        return ;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans=0;
        int l=0;int r=50*50;
        while(l<=r){
            int mid = (l+r)/2;
            vis = vector<vector<int>>(n,vector<int>(m,0));
            dfs(mid,0,0,grid);
            if(vis[n-1][m-1]){
                r=mid-1;
                ans=mid;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};