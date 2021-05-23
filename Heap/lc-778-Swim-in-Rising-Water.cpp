#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int n,m;
    
    bool isSafe(int x,int y){
        if(x>=0&&y>=0&&x<n&&y<m)
            return true;
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        priority_queue<pii,vector<pii>,greater<pii>> p;
        vector<vector<int>> vis(n,vector<int>(m,0));
        p.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int ans =0;
        while(!p.empty()){
            auto x = p.top();
            p.pop();
            int a = x.second.first;
            int b = x.second.second;
            ans = max(ans,x.first);
            // cout<<x.first<<" "<<a<<" "<<b<<endl;
            if(a==n-1 && b==m-1)
                return ans;
            
            for(int i=0;i<4;i++){
                int x = a+dx[i];
                int y = b+dy[i];
                if(isSafe(x,y) && vis[x][y]==0){
                    p.push({grid[x][y],{x,y}});
                    vis[x][y]=1;
                }
            }
        }
        return ans;
    }
};