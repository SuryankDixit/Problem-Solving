#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    #define INF 2147483647
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    queue<pi> q;
    int n1,n2;
    
    void solve(vector<vector<int>>& m,vector<vector<int>> &v){
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
                    if(x>=0 && x<n1 && y>=0 && y<n2 && v[x][y]!=-1){
                        m[x][y]=m[t.first][t.second]+1;
                        q.push({x,y});
                        v[x][y]=-1;
                    }
                }
            }
        }
    }
    void wallsAndGates(vector<vector<int>> &m) {
        if(m.empty())
            return ;
        
        n1=m.size();
        n2=m[0].size();
        vector<vector<int>> v(n1,vector<int>(n2,1));
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(m[i][j]==0){
                    q.push({i,j});
                    v[i][j]=-1;
                }
                if(m[i][j]==-1){
                    v[i][j]=-1;
                }
            }
        }
        solve(m,v);
    }
};
