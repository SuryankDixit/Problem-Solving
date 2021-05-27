#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isValid(int i,int j,int n1,int n2){
        if(i<0||j<0||i>=n1||j>=n2)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0)
                    grid[i][j]=-1;
                else if(grid[i][j]==1)
                    cnt++;
                else
                    q.push({i,j});
            }
        }
        if(cnt==0)
            return 0;
        
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        
        int ans=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                pair<int,int> t=q.front();
                q.pop();
                grid[t.first][t.second]=-1;
                for(int i=0;i<4;i++){
                    int x=t.first + dx[i];
                    int y=t.second + dy[i];
                    if(isValid(x,y,grid.size(),grid[0].size()) && grid[x][y]!=-1 && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!=-1)
                    return -1;
            }
        }
        return ans-1;
    }
};