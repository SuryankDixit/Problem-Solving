#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    queue<pi> q;
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int a,b;
    
    int bfs(vector<vector<int>>& m,vector<vector<int>> &v){
        int ans=-1;
        int dis=0;
        while(!q.empty()){
            int k=q.size();
            dis++;
            while(k--){
                pi t=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = t.first+dx[i];
                    int y = t.second+dy[i];
                    if(x>=0&&y>=0&&x<a&&y<b&&v[x][y]!=-1){
                        q.push({x,y});
                        m[x][y]=dis;
                        v[x][y]=-1;
                        ans=max(ans,m[x][y]);
                    }
                }
            }
        }
        return ans;
    }
    
    int maxDistance(vector<vector<int>>& m) {
        if(m.empty())
            return -1;
        a=m.size();
        b=m[0].size();
        
        vector<vector<int>> v(a,vector<int>(b,0));
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(m[i][j]==1){
                    q.push({i,j});
                    v[i][j]=-1;
                }
            }
        }
        return bfs(m,v);
    }
};