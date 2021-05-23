#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    queue<pi> q;
    int n1,n2;
    
    void solve(vector<vector<int>>& m,vector<vector<int>>& dist){
        int dis=0;
        while(!q.empty()){
            int k=q.size();
            dis++;
            while(k--){
                pi t = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=t.first+dx[i];
                    int y=t.second+dy[i];
                    if(x>=0 && x<n1 && y>=0 && y<n2 && m[x][y]!=-1){
                        dist[x][y]=dist[t.first][t.second]+1;
                        q.push({x,y});
                        m[x][y]=-1;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        
        if(m.empty())
            return m;
        
        n1=m.size();
        n2=m[0].size();
        vector<vector<int>> dist(n1,vector<int>(n2,0));
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(m[i][j]==0){
                    q.push({i,j});
                    m[i][j]=-1;
                }
            }
        }
        solve(m,dist);
        return dist;
    }
};